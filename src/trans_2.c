/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:07:46 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/12 17:45:54 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float *init_zero(float *mat_s, float *mat_t, float *mat_r, float *aux)
{
	float *mat;

	ft_memsetf(mat_s, 0, 16);
    ft_memsetf(mat_t, 0, 16);
    ft_memsetf(mat_r, 0, 16);
    ft_memsetf(aux, 0, 16);
	mat = ft_callocf(16, sizeof(float));
    if(!mat)
	{
		return (handle_error(ERR_MALL), NULL);
	}   
	return (mat) ;
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
	//if (elem->type == PL)
	//	rotation_matrix(rotation_angles(elem->vec), mat_r);
    //else
		identity_matrix(mat_r);
	return ;
}
