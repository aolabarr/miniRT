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
	t_vec temp;
	t_pos res;

	temp = scalar_product(ray.vec, t);
	res = new_lineal_point(ray.origin, temp, 1);
	return (res);
}


t_hit	sphere_intersection(t_ray ray, t_element elem)
{

	float a;
	float b;
	float c;
	float dis;
	t_hit inters;
	
	a = dot_product(ray.vec, ray.vec);
	b = 2 * dot_product(ray.vec, rest_coord(ray.origin, zero_pos()));
	c = dot_product(rest_coord(ray.origin, zero_pos()), rest_coord(ray.origin, zero_pos())) - 1;
	dis = (b * b) - (4 * a * c);
	if (dis < -EPSILON)
	{
		inters.hit = false;
		inters.t1 = inters.t2 = 0;
		inters.elem = elem;
		
	}
	else
	{
		inters.t1 = (- b - sqrtf(dis)) / (2 * a);
		inters.t2 = (- b + sqrtf(dis)) / (2 * a);
		inters.elem = elem;
		if ((inters.t1 < -EPSILON && inters.t2 < -EPSILON) || (ft_abs(inters.t1) < EPSILON && ft_abs(inters.t2) < EPSILON))
			inters.hit = false;
		else
			inters.hit = true;
			
	}

	return (inters);
}


t_hit plane_intersection(t_ray ray, t_element elem)
{

	t_hit inters;

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


t_hit cylinder_intersection(t_ray ray, t_element elem)
{
	t_hit	inters;
	float	a;
	float	b;
	float	c;
	float	dis;
	(void)elem;

	inters.elem = elem;
	inters.hit = false;
	a = ray.vec.x * ray.vec.x + ray.vec.z * ray.vec.z;
	if (ft_abs(a) < EPSILON) 
		return (inters);
	b = 2 * ray.origin.x * ray.vec.x + 2 * ray.origin.z * ray.vec.z;
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	dis = (b * b) - 4 * a *c;
	if (dis < -EPSILON) 
		return (inters);
	inters.t1 = (- b - sqrtf(dis)) / (2 * a);
	inters.t2 = (- b + sqrtf(dis)) / (2 * a);
	inters.elem = elem;
	if ((inters.t1 < -EPSILON && inters.t2 < -EPSILON) || (ft_abs(inters.t1) < EPSILON && ft_abs(inters.t2) < EPSILON))
		return (inters);

	float min_y = -elem.height / elem.radio / 2;

	float max_y = elem.height / elem.radio / 2;
	
	float y1 = ray.origin.y + inters.t1 * ray.vec.y;
	float y2 = ray.origin.y + inters.t2 * ray.vec.y;	
	if (!is_equal(y1, min_y) && (y1 > min_y) && !is_equal(y1, max_y)  && (y1 < max_y))
		inters.hit = true;
	else if (!is_equal(y2, min_y) && (y2 > min_y) && !is_equal(y2, max_y)  && (y2 < max_y))
		inters.hit = true;
	return (inters);
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


