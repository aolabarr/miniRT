/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/20 15:51:01 by aolabarr         ###   ########.fr       */
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

float *shearing_matrix(t_shear shear)
{
    float *mat;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[1] = shear.xy;
    mat[2] = shear.xz;
    mat[4] = shear.yx;
    mat[6] = shear.yz;
    mat[8] = shear.zx;
    mat[9] = shear.zy;
    return (mat);
}
