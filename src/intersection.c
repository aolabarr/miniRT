/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:13:32 by binary            #+#    #+#             */
/*   Updated: 2025/03/26 15:27:32 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pos	position(t_ray ray, float t)
{
	t_vec temp;
	t_pos res;

	temp = scalar_product(ray.vec, t);
	res = new_lineal_point(ray.origin, temp, 1);
	return (res);
}

// t_pos new_lineal_point(t_pos point, t_vec vec)
// {
// 	t_pos	res;
	
// 	res.x = point.x + vec.x;
// 	res.y = point.y + vec.y;
// 	res.z = point.z + vec.z;
// 	res.w = point.w + vec.w;
// 	return (res);
// }

/* 
a ← dot(ray.direction, ray.direction)
b ← 2 * dot(ray.direction, sphere_to_ray)
c ← dot(sphere_to_ray, sphere_to_ray) - radius^2
discriminant ← b² - 4 * a * c 
*/

t_hit	calculate_hit(t_ray ray, t_element elem)
{

	float a;
	float b;
	float c;
	float dis;
	t_hit res;
	
	a = dot_product(ray.vec, ray.vec);
	b = 2 * dot_product(ray.vec, rest_coord(ray.origin, elem.pos));
	c = dot_product(rest_coord(ray.origin, elem.pos), rest_coord(ray.origin, elem.pos)) - ((elem.diam/2) * (elem.diam/2));
	dis = (b * b) - (4 * a * c);
	if (dis < 0)
	{
		//printf("no hay hit\n");
		res.hit = false;
		res.t1 = res.t2 = 0;
		return (res);
	}
	res.hit = true;
	if (dis == 0)
	{
		res.t1 = -b / (2 * a);
		res.t2 = res.t1;
	}
	else if (dis > 0)
	{
		res.t1 = (- b - sqrtf(dis)) / (2 * a);
		res.t2 = (- b + sqrtf(dis)) / (2 * a);

	}
	return (res);
}

/*
intersección en el plano

t = (punto en el plano - origen del rayo) * normal del plano / (dirección del rayo * normal del plano)

*/

t_hit plane_intersection(t_ray ray, t_element elem)
{
	t_hit	hit;
	t_vec	vec1;
	float	numerator;
	float	denominator;
	float	t;
	
	vec1 = rest_coord(elem.pos, ray.origin);
	numerator = dot_product(vec1, elem.vec);
	denominator = dot_product (ray.vec, elem.vec);
	if (myabs(denominator) < EPSILON) // rayo y plano son paralelos?
	{
		hit.hit = false;
		hit.t1 = hit.t2 = 0;
		return (hit);
	}
	t = numerator / denominator;
	if (t < EPSILON)
	{
		hit.hit = false;
		hit.t1 = hit.t2 = 0;
		return (hit);
	}
	hit.hit = true;
	hit.t1 = hit.t2 = t;
	return (hit);
}