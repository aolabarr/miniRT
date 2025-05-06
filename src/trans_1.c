/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:17:46 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 14:09:49 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	init_trans_matrix(t_data *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_elem)
	{
		if (get_trans_matrix(&scene->elem[i], scene))
			return (EXIT_FAILURE);
		if (get_trans_inv_matrix(&scene->elem[i], scene))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_trans_matrix(t_element *elem, t_data *scene)
{
	float	mat_s[16];
	float	mat_t[16];
	float	mat_r[16];
	float	aux[16];

	elem->tr_mat = init_zero(mat_s, mat_t, mat_r, aux);
	if (!elem->tr_mat)
		return (EXIT_FAILURE);
	handle_scale(elem, mat_s, NORMAL);
	translation_matrix(elem->pos, mat_t);
	handle_rotation(elem, mat_r, NORMAL, scene);
	multiply_matrix(mat_r, mat_s, aux);
	multiply_matrix(mat_t, aux, elem->tr_mat);
	return (EXIT_SUCCESS);
}

int	get_trans_inv_matrix(t_element *elem, t_data *scene)
{
	float	mat_s[16];
	float	mat_t[16];
	float	mat_r[16];
	float	aux[16];

	elem->tri_mat = init_zero(mat_s, mat_t, mat_r, aux);
	if (!elem->tri_mat)
		return (EXIT_FAILURE);
	handle_scale(elem, mat_s, INVERSE);
	handle_rotation(elem, mat_r, INVERSE, scene);
	translation_matrix(scalar_product(elem->pos, -1), mat_t);
	multiply_matrix(mat_r, mat_t, aux);
	multiply_matrix(mat_s, aux, elem->tri_mat);
	return (EXIT_SUCCESS);
}
