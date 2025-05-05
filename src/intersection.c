/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:13:32 by binary            #+#    #+#             */
/*   Updated: 2025/05/03 13:55:44 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pos	position(t_ray ray, float t)
{
	t_vec	temp;
	t_pos	res;

	temp = scalar_product(ray.vec, t);
	res = new_lineal_point(ray.origin, temp, 1);
	return (res);
}

t_hit	sphere_intersection(t_ray ray, t_element elem)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	t_hit	inters;

	inters.hit = false;
	inters.t1 = 0;
	inters.t2 = 0;
	inters.elem = elem;
	a = dot_product(ray.vec, ray.vec);
	b = 2 * dot_product(ray.vec, rest_coord(ray.origin, zero_pos()));
	c = dot_product(rest_coord(ray.origin, zero_pos()), rest_coord(ray.origin, zero_pos())) - 1;
	dis = (b * b) - (4 * a * c);
	if (dis < -EPSILON)
		return (inters);
	inters.t1 = (-b - sqrtf(dis)) / (2 * a);
	inters.t2 = (-b + sqrtf(dis)) / (2 * a);
	inters.hit = inters.t1 > EPSILON || inters.t2 > EPSILON;
	return (inters);
}

t_hit	plane_intersection(t_ray ray, t_element elem)
{
	t_hit	inters;

	inters.elem = elem;
	inters.hit = false;
	if (ft_abs(ray.vec.y) < EPSILON)
		return (inters);
	else
	{
		inters.t1 = -ray.origin.y / ray.vec.y;
		inters.t2 = inters.t1;
		if (inters.t1 > EPSILON)
		{
			inters.elem = elem;
			inters.hit = true;
		}
		else
			inters.hit = false;
	}
	return (inters);
}

t_hit	cylinder_intersection(t_ray ray, t_element elem)
{
	t_hit	inters;
	float	a;
	float	b;
	float	c;
	float	dis;

	inters.elem = elem;
	inters.hit = false;
	a = ray.vec.x * ray.vec.x + ray.vec.z * ray.vec.z;
	if (ft_abs(a) < EPSILON)
		return (inters);
	b = 2 * (ray.origin.x * ray.vec.x + ray.origin.z * ray.vec.z);
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	dis = b * b - 4 * a * c;
	if (dis < -EPSILON)
		return (inters);
	inters.t1 = (-b - sqrtf(dis)) / (2 * a);
	inters.t2 = (-b + sqrtf(dis)) / (2 * a);
	inters.hit = truncate_cylinder(ray, elem, inters.t1, inters.t2);
	return (inters);
}

bool	truncate_cylinder(t_ray ray, t_element elem, float t1, float t2)
{
	float	y1;
	float	y2;
	float	min_y;
	float	max_y;
	bool	hit;

	hit = false;
	min_y = -elem.height / elem.radio / 2.0f;
	max_y = elem.height / elem.radio / 2.0f;
	y1 = ray.origin.y + t1 * ray.vec.y;
	if (t1 > EPSILON && y1 > min_y && y1 < max_y)
		hit = true;
	y2 = ray.origin.y + t2 * ray.vec.y;
	if (t2 > EPSILON && y2 > min_y && y2 < max_y)
		hit = true;
	return (hit);
}
