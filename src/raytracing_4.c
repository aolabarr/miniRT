/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:33:09 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/09 15:06:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	create_ray(t_data *scene, t_image img, int x, int y)
{
	t_pos	pixel_pos;
	t_ray	ray;

	pixel_pos = calc_pixel_position(x, y, img.canvas, scene->height);
	ray.origin = scene->cam.pos;
	ray.vec = normalize(rest_coord(pixel_pos, scene->cam.pos));
	return (ray);
}

t_hit	find_hit(t_data *scene, t_hit *inters)
{
	int		i;
	t_hit	hit;

	hit.hit = false;
	i = 0;
	while (i < scene->n_elem)
	{
		if (inters[i].hit)
		{
			update_hit(&hit, inters[i]);
		}
		i++;
	}
	return (hit);
}

void	update_hit(t_hit *hit, t_hit inter)
{
	if ((*hit).hit == false)
		*hit = inter;
	else
	{
		if (is_equal(hit_t(*hit), hit_t(inter))
			|| (hit_t(*hit) - hit_t(inter)) < 0)
			return ;
		else
			*hit = inter;
	}
	return ;
}
