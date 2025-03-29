/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:12:28 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/29 18:08:14 by aolabarr         ###   ########.fr       */
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

float	lightning(t_data *scene, t_element elem, t_pos point, t_vec normal)
{
	t_vec	lightv;
	t_vec	eyev;
	float	colors[3];
	float	light_dot_normal;
	t_vec	reflectv;
	float	reflect_dot_eye;
	float	factor;

	eyev = normalize(rest_coord(scene->cam.pos, point));
	lightv = normalize(rest_coord(scene->lig.pos, point));
	colors[0] = scene->lig.bright * elem.material.ambient;
	light_dot_normal = dot_product(lightv, normal);
	if (light_dot_normal < -EPSILON)
	{
		colors[1] = 0;
		colors[2] = 0;
	}
	else
	{
		colors[1] = scene->lig.bright * elem.material.diffuse * light_dot_normal;
		reflectv = reflect_at(opp_vector(lightv), normal);
		reflect_dot_eye = dot_product(reflectv, eyev);
		if (reflect_dot_eye < -EPSILON || ft_abs(reflect_dot_eye) < EPSILON)
			colors[2] = 0;
		else
		{
			factor = ft_pow(reflect_dot_eye, elem.material.shini);
			colors[2] = scene->lig.bright * elem.material.specular * factor;
		}	
	}
	return (colors[0] + colors[1] + colors[2]);
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
