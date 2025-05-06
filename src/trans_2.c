/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:07:46 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/17 17:12:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*init_zero(float *mat_s, float *mat_t, float *mat_r, float *aux)
{
	float	*mat;

	ft_memsetf(mat_s, 0, 16);
	ft_memsetf(mat_t, 0, 16);
	ft_memsetf(mat_r, 0, 16);
	ft_memsetf(aux, 0, 16);
	mat = ft_callocf(16, sizeof(float));
	if (!mat)
	{
		return (handle_error(ERR_MALL), NULL);
	}
	return (mat);
}

void	handle_scale(t_element *elem, float *mat_s, int dir)
{
	if (elem->type == SP && dir == NORMAL)
		scale_matrix(elem->radio, elem->radio, elem->radio, mat_s);
	else if (elem->type == SP && dir == INVERSE)
		scale_matrix(1 / elem->radio, 1 / elem->radio, 1 / elem->radio, mat_s);
	else if (elem->type == CY && dir == NORMAL)
		scale_matrix(elem->radio, elem->radio, elem->radio, mat_s);
	else if (elem->type == CY && dir == INVERSE)
		scale_matrix(1 / elem->radio, 1 / elem->radio, 1 / elem->radio, mat_s);
	else
		identity_matrix(mat_s);
	return ;
}

void	handle_rotation(t_element *elem, float *mat_r, int dir)
{
	(void)elem, (void)mat_r, (void)dir;
	if (elem->type == PL && dir == NORMAL)
		rotation_matrix_from_to(WORLD_Y, elem->vec, mat_r);
	else if (elem->type == PL && dir == INVERSE)
		rotation_matrix_from_to(elem->vec, WORLD_Y, mat_r);
	else if (elem->type == CY && dir == NORMAL)
		rotation_matrix_from_to(WORLD_Y, elem->vec, mat_r);
	else if (elem->type == CY && dir == INVERSE)
		rotation_matrix_from_to(elem->vec, WORLD_Y, mat_r);
	else
		identity_matrix(mat_r);
	return ;
}

void	rotation_matrix_from_to(t_vec from, t_vec to, float *mat)
{
	t_vec	axis;
	float	cos_theta;

	axis = cross_product(normalize(from), to);
	cos_theta = dot_product(from, to);
	if (ft_abs(cos_theta - 1.0) < EPSILON)
		identity_matrix(mat);
	if (ft_abs(cos_theta + 1.0) < EPSILON)
		rodrigues_matrix(axis, PI, mat);
	else
		rodrigues_matrix(axis, acos(cos_theta), mat);
	return ;
}

void	rodrigues_matrix(t_vec a, float angle, float *mat)
{
	float	c;
	float	s;

	c = cos(angle);
	s = sin(angle);
	identity_matrix(mat);
	mat[0] = c + a.x * a.x * (1 - c);
	mat[1] = a.x * a.y * (1 - c) - a.z * s;
	mat[2] = a.x * a.z * (1 - c) + a.y * s;
	mat[4] = a.y * a.x * (1 - c) + a.z * s;
	mat[5] = c + a.y * a.y * (1 - c);
	mat[6] = a.y * a.z * (1 - c) - a.x * s;
	mat[8] = a.z * a.x * (1 - c) - a.y * s;
	mat[9] = a.z * a.y * (1 - c) + a.x * s;
	mat[10] = c + a.z * a.z * (1 - c);
	return ;
}
