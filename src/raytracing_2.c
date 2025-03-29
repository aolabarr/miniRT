/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:12:28 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/26 19:51:46 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec	normal_at(t_element elem, t_pos hit_wd_point)
{
	t_pos hit_ob_point;
	t_vec ob_normal;
	t_vec wd_normal;
	float aux_mat[16];

	multiply_matrix_pos(elem.tri_mat, hit_wd_point, &hit_ob_point);
	ob_normal = rest_coord(hit_ob_point, zero_pos());
	transpose_matrix(elem.tri_mat, aux_mat);
	multiply_matrix_vector(aux_mat, ob_normal, &wd_normal);
	wd_normal.w = 0;
	return (normalize(wd_normal));
}
t_vec	reflect_at(t_vec in, t_vec normal)
{
	return (rest_coord(in, scalar_product(normal, 2.0 * dot_product(in, normal))));
}
/*
float	lightning(t_data scene, t_element elem, t_pos point, t_vec normal)
{
	t_color effective_color;
	t_vec	light_vec;

	effective_color = add_color_intensity(elem.color, scene.lig.bright);


}
*/

t_color	add_color_intensity(t_color color, float intensity)
{
	t_color res_color;

	res_color.blue = color.blue * intensity;
	res_color.red = color.red * intensity;
	res_color.green = color.green * intensity;
	return (res_color);
}
