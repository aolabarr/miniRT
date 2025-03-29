/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:13:32 by binary            #+#    #+#             */
/*   Updated: 2025/03/29 11:05:34 by beiglesi         ###   ########.fr       */
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

t_hit	sphere_intersection(t_ray ray, t_element elem)
{

	float a;
	float b;
	float c;
	float dis;
	t_hit res;
	
	(void)elem;
	t_hit hit;
	
	a = dot_product(ray.vec, ray.vec);
	b = 2 * dot_product(ray.vec, rest_coord(ray.origin, zero_pos()));
	c = dot_product(rest_coord(ray.origin, zero_pos()), rest_coord(ray.origin, zero_pos())) - 1;
	dis = (b * b) - (4 * a * c);
	if (dis < 0)
	{
		//printf("no hay hit\n");
		hit.hit = false;
		hit.t1 = hit.t2 = 0;
		return (hit);
	}
	hit.hit = true;
	if (dis < 0)
	{
		hit.t1 = -b / (2 * a);
		hit.t2 = hit.t1;
	}
	else // dis > 0
	{
		hit.t1 = (- b - sqrtf(dis)) / (2 * a);
		hit.t2 = (- b + sqrtf(dis)) / (2 * a);

	}
	return (hit);
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


t_hit cylinder_intersection(t_ray ray, t_element elem)
{
	t_hit	hit;
	float	a;
	float	b;
	float	c;
	float	dis;

	a = ray.vec.x * ray.vec.x + ray.vec.z * ray.vec.z;
	if (a < EPSILON) //rayo paralelo al cilindro 
	{
		hit.hit = false;
		hit.t1 = hit.t2 = 0;
		return (hit);
	}
	b = 2 * ray.origin.x * ray.vec.x + 2 * ray.origin.z * ray.vec.z;
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	dis = (b * b) - 4 * a *c;
	if (dis < EPSILON) //no hay intersección
	{
		hit.hit = false;
		hit.t1 = hit.t2 = 0;
		return (hit);
	}
	else // dis > 0 y hay intersesccion
	{
		hit.t1 = (- b - sqrtf(dis)) / (2 * a);
		hit.t2 = (- b + sqrtf(dis)) / (2 * a);

	}
	return (hit);
}

t_pos	zero_pos(void)
{
	t_pos zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	zero.w = 1;
	return(zero);
}


