/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:15:21 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 10:24:21 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_canvas(t_data *scene)
{
	t_pos	center;
	t_vec	right_up[2];
	t_vec	world_up;

	center = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	if(is_equal(scene->cam.vec.y, 1.0) || is_equal(scene->cam.vec.y, -1.0))
		world_up = WORLD_Z;
	else
		world_up = WORLD_Y;
	right_up[0] = normalize(cross_product(scene->cam.vec, world_up));
	right_up[1] = normalize(cross_product(right_up[0], scene->cam.vec));
	put_canvas_values(scene, right_up, center);
	return ;
}

void	put_canvas_values(t_data *scene, t_vec *right_up, t_pos center)
{
	float hsize;
	float vsize;
	t_pos	aux;

	hsize = 2 * tan((scene->cam.fov * PI / 180) / 2);
	vsize = hsize / ASPECT_RATIO;
	aux = new_lineal_point(center, right_up[0], -hsize / 2);
	scene->img.canvas[0] = new_lineal_point(aux, right_up[1], -vsize / 2);
	aux = new_lineal_point(center, right_up[0], hsize / 2);
	scene->img.canvas[1] = new_lineal_point(aux, right_up[1], -vsize / 2);
	aux = new_lineal_point(center, right_up[0], -hsize / 2);
	scene->img.canvas[2] = new_lineal_point(aux, right_up[1], vsize / 2);
	aux = new_lineal_point(center, right_up[0], hsize / 2);
	scene->img.canvas[3] = new_lineal_point(aux, right_up[1], vsize / 2);
	return ;
}
