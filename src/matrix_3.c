/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/02 18:25:42 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	determinant_matrix(float *mat)
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

void	translation_matrix(t_pos point, float *mat)
{
	identity_matrix(mat);
	mat[3] = point.x;
	mat[7] = point.y;
	mat[11] = point.z;
	return ;
}

void	scale_matrix(float x, float y, float z, float *mat)
{
	identity_matrix(mat);
	mat[0] = x;
	mat[5] = y;
	mat[10] = z;
	return ;
}

void	shearing_matrix(t_shear shear, float *mat)
{
	identity_matrix(mat);
	mat[1] = shear.xy;
	mat[2] = shear.xz;
	mat[4] = shear.yx;
	mat[6] = shear.yz;
	mat[8] = shear.zx;
	mat[9] = shear.zy;
	return ;
}
