/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:13:32 by binary            #+#    #+#             */
/*   Updated: 2025/03/21 12:56:47 by binary           ###   ########.fr       */
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

