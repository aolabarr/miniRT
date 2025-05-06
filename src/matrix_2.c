/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:55 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/12 15:28:56 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rotation_x_matrix(float angle, float *mat)
{
	angle = PI / 180 * angle;
	identity_matrix(mat);
	mat[5] = cos(angle);
	mat[6] = -sin(angle);
	mat[9] = sin(angle);
	mat[10] = cos(angle);
	return ;
}

void	rotation_y_matrix(float angle, float *mat)
{
	angle = PI / 180 * angle;
	identity_matrix(mat);
	mat[0] = cos(angle);
	mat[2] = sin(angle);
	mat[8] = -sin(angle);
	mat[10] = cos(angle);
	return ;
}

void	rotation_z_matrix(float angle, float *mat)
{
	angle = PI / 180 * angle;
	identity_matrix(mat);
	mat[0] = cos(angle);
	mat[1] = -sin(angle);
	mat[4] = sin(angle);
	mat[5] = cos(angle);
	return ;
}

void	rotation_matrix(t_ang angles, float *mat)
{
	float	mat1[16];
	float	mat2[16];
	float	aux[16];

	rotation_z_matrix(angles.z, mat1);
	rotation_y_matrix(angles.y, mat2);
	multiply_matrix(mat2, mat1, aux);
	rotation_x_matrix(angles.x, mat1);
	multiply_matrix(mat1, aux, mat);
	return ;
}

void	rotation_inv_matrix(t_ang angles, float *mat)
{
	float	mat1[16];
	float	mat2[16];
	float	mat3[16];
	float	aux[16];

	rotation_z_matrix(angles.z, mat1);
	transpose_matrix(mat1, mat2);
	rotation_y_matrix(angles.y, mat1);
	transpose_matrix(mat1, mat3);
	multiply_matrix(mat3, mat2, aux);
	rotation_x_matrix(angles.x, mat1);
	transpose_matrix(mat1, mat2);
	multiply_matrix(mat2, aux, mat);
	return ;
}
