/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/22 21:12:52 by aolabarr         ###   ########.fr       */
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

void rotation_angles(t_vec vec, float theta[3])
{
    float magnitude;
	
	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (magnitude != 1.0f)
    {
        vec.x /= magnitude;
        vec.y /= magnitude;
        vec.z /= magnitude;
    }
    // Ángulo alrededor del eje Z (proyección sobre el plano XY)
    theta[0] = atan2(vec.y, vec.x);
    // Ángulo alrededor del eje Y (proyección sobre el plano XZ)
    theta[1] = atan2(-vec.z, sqrt(vec.x * vec.x + vec.y * vec.y));
    // Ángulo alrededor del eje X (proyección sobre el plano YZ)
    theta[2] = atan2(vec.y, vec.z);
	return;
}
float *trans_matrix(t_element elem)
{
    float *res;
	//float	mat1[16];
	//float	mat2[16];
    (void)elem;

    res = ft_calloc(16, sizeof(float));
    if(!res)
        return (NULL);
	// Realizar las transiformaciones en orden correcto

    return (res);
}
