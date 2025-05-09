/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:28:06 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/09 15:52:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	lightning(t_data *scene, t_comps comps, int in_shadow)
{
	t_vec	lightv;
	float	colors[3];
	float	light_dot_normal;
	t_vec	reflectv;
	float	reflect_dot_eye;

	(void)in_shadow;
	ft_memsetf(colors, 0.0, 3);
	lightv = normalize(rest_coord(scene->lig.pos, comps.over_point));
	colors[0] = get_ambient_factor(scene, comps);
	if (in_shadow == SHADOW)
		return (colors[0]);
	light_dot_normal = dot_product(lightv, comps.normal);
	if (light_dot_normal < -EPSILON)
		diffuse_specular_zero(colors);
	else
	{
		colors[1] = get_diffuse_factor(scene, comps, light_dot_normal);
		reflectv = reflect_at(opp_vector(lightv), comps.normal);
		reflect_dot_eye = dot_product(reflectv, comps.eyev);
		colors[2] = get_specular_factor(reflect_dot_eye, scene, comps);
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
	float	factor;

	factor = ft_pow(reflect_dot_eye, comps.elem.material.shini);
	return (scene->lig.bright * comps.elem.material.specular * factor);
}

int	is_shadowed(t_data *scene, t_pos point)
{
	t_vec	v;
	t_ray	ray;
	t_hit	*inters;
	t_hit	hit;
	float	dist_light;

	v = rest_coord(scene->lig.pos, point);
	dist_light = magnitude(v);
	ray.origin = point;
	ray.vec = normalize(v);
	inters = intersect_world(ray, scene);
	hit = find_hit(scene, inters);
	free(inters);
	if (hit.hit && hit_t(hit) < dist_light)
		return (SHADOW);
	return (NO_SHADOW);
}
