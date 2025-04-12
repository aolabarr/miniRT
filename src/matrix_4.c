/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/12 15:34:01 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float determinant_matrix(float *mat)
{
    float	det;
    int		i;

	det = 0;
	i = 0;
    while (i < 4)
    {
        det += mat[i] * cofactor(mat, 0, i);
        i++;
    }
    return (det);
}

void    translation_matrix(t_pos point, float *mat)
{
    identity_matrix(mat);
    mat[3] = point.x;
    mat[7] = point.y;
    mat[11] = point.z;
    return;
}

void    scale_matrix(float x, float y, float z, float *mat)
{
    identity_matrix(mat);
    mat[0] = x;
    mat[5] = y;
    mat[10] = z;
    return;
}

void    shearing_matrix(t_shear shear,  float *mat)
{
    identity_matrix(mat);
    mat[1] = shear.xy;
    mat[2] = shear.xz;
    mat[4] = shear.yx;
    mat[6] = shear.yz;
    mat[8] = shear.zx;
    mat[9] = shear.zy;
    return;
}

t_ang rotation_angles(t_vec vec)
{
    float magnitude;
    t_ang angles;
	
	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (magnitude != 1.0f)
    {
        vec.x /= magnitude;
        vec.y /= magnitude;
        vec.z /= magnitude;
    }
    // Ángulo alrededor del eje Z (proyección sobre el plano XY)
    angles.x = atan2(vec.y, vec.x);
    // Ángulo alrededor del eje Y (proyección sobre el plano XZ)
    angles.y = atan2(-vec.z, sqrt(vec.x * vec.x + vec.y * vec.y));
    // Ángulo alrededor del eje X (proyección sobre el plano YZ)
    angles.z = atan2(vec.y, vec.z);
	return (angles);
}
