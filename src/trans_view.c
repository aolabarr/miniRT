/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:17:58 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/05 12:10:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	view_transform(t_pos from, t_pos to, t_vec up, float *mat)
{
	t_vec	forward;
	t_vec	left;
	t_vec	true_up;
	float	orientation[16];
	float	trans[16];

	forward = normalize(rest_coord(to, from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	identity_matrix(orientation);
	orientation[0] = left.x;
	orientation[1] = left.y;
	orientation[2] = left.z;
	orientation[4] = true_up.x;
	orientation[5] = true_up.y;
	orientation[6] = true_up.z;
	orientation[8] = -forward.x;
	orientation[9] = -forward.y;
	orientation[10] = -forward.z;
	identity_matrix(mat);
	translation_matrix(from, mat);
	multiply_matrix(orientation, trans, mat);
	return ;
}

void	transform_cam(t_pos from, t_pos to, t_vec up, t_data *scene)
{
	float	trans_mat[16];
	t_pos	aux;

	view_transform(from, to, up, trans_mat);
	multiply_matrix_pos(trans_mat, scene->cam.pos, &aux);
	scene->cam.pos = aux;
	return ;
}
