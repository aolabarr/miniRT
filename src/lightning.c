/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:28:06 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/02 19:31:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	lightning(t_data *scene, t_comps comps)
{
	t_vec	lightv;
	float	colors[3];
	float	light_dot_normal;
	t_vec	reflectv;
	float	reflect_dot_eye;

	lightv = normalize(rest_coord(scene->lig.pos, comps.point));
	colors[0] = scene->lig.bright * comps.elem.material.ambient;
	light_dot_normal = dot_product(lightv, comps.normal);
	if (light_dot_normal < -EPSILON)
		diffuse_specular_zero(colors);
	else
	{
		colors[1] = scene->lig.bright * comps.elem.material.diffuse * light_dot_normal;
		reflectv = reflect_at(opp_vector(lightv), comps.normal);
		reflect_dot_eye = dot_product(reflectv, comps.eyev);
		if (reflect_dot_eye < -EPSILON || ft_abs(reflect_dot_eye) < EPSILON)
			colors[2] = 0;
		else
			colors[2] = calculate_specular(scene, comps, reflect_dot_eye);
	}
	return (colors[0] + colors[1] + colors[2]);
}

void	diffuse_specular_zero(float *colors)
{
	colors[1] = 0;
	colors[2] = 0;
	return ;
}

float	calculate_specular(t_data *scene, t_comps comps, float reflect_dot_eye)
{
	float factor;

	factor = ft_pow(reflect_dot_eye, comps.elem.material.shini);
	return (scene->lig.bright * comps.elem.material.specular * factor);
}
