/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:05:48 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/26 11:19:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pos calc_pixel_position(int x, int y, t_pos *canvas)
{
	float u;
	float v;
	t_pos	pixel_pos;
	t_pos	aux[4];

	u = 1.0 - ((float)x / (float)(WIDTH - 1));
	v = 1.0 - ((float)y / (float)(HEIGHT - 1));
	aux[0] = scalar_product(canvas[1], (1 - u) * (1 - v));
	aux[1] = scalar_product(canvas[0], u * (1 - v));
	aux[2] = scalar_product(canvas[3], (1 - u) * v);
	aux[3] = scalar_product(canvas[2], u * v);
	pixel_pos.x = aux[0].x + aux[1].x + aux[2].x + aux[3].x;
	pixel_pos.y = aux[0].y + aux[1].y + aux[2].y + aux[3].y;
	pixel_pos.z = aux[0].z + aux[1].z + aux[2].z + aux[3].z;
	pixel_pos.w = 1;
	return (pixel_pos);
}
void	ray_transform_to_local(t_element *elem, t_ray ray, t_ray *ray_local)
{
	multiply_matrix_vector(elem->tri_mat, ray.vec, &ray_local->vec);
	//ray_local->vec = ray.vec;
	//ray_local->origin = rest_coord(ray.origin, elem->pos);
	multiply_matrix_pos(elem->tri_mat, ray.origin, &ray_local->origin);
	return ;
}
t_pos	get_hit_point(t_ray ray, t_hit hit)
{
	float	t;
	t_pos	point;
	
	t = hit_t(hit);
	point = new_lineal_point(ray.origin, ray.vec, t);
	return (point);
}

float	hit_t(t_hit hit)
{	
	if (hit.t1 > 0 && hit.t1 < hit.t2)
		return(hit.t1);
	else if (hit.t2 > 0 && hit.t2 < hit.t1)
		return(hit.t2);
	else
		return (NO_HIT);
}

void	normal_at(t_element elem, t_pos hit_point)
{
	(void)elem;
	(void)hit_point;
}
