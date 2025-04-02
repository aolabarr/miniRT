/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:12:28 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/02 19:31:56 by aolabarr         ###   ########.fr       */
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


t_color	add_color_intensity(t_color color, float intensity)
{
	t_color res_color;

	res_color.red = clamp_color(color.red * intensity);
	res_color.green = clamp_color(color.green * intensity);
	res_color.blue = clamp_color(color.blue * intensity);
	return (res_color);
}

t_color	create_color(float r, float g, float b)
{
	t_color color;

	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

void	init_pong_parameters(t_data *scene)
{
	int i;

	i = 0;
	while(i < scene->n_elem)
	{
		scene->elem[i].material.ambient = scene->amb.ratio;
		scene->elem[i].material.diffuse = DIFFUSE;
		scene->elem[i].material.specular = SPECULAR; 
		scene->elem[i].material.shini = SHININESS;
		i++;
	}
}

