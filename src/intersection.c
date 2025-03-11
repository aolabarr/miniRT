/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:13:32 by binary            #+#    #+#             */
/*   Updated: 2025/03/11 11:58:35 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pos	position(t_ray ray, float t)
{
	t_vec temp;
	t_pos res;

	temp = scalar_product(ray.vec, t);
	res = new_lineal_point(ray.origin, temp);
	return (res);
}

/* revisar esto para "unificar" t_vector sum y t_pos new_lineal_point con un t_coord sum*/

t_pos new_lineal_point(t_pos point, t_vec vec)
{
	t_pos	res;
	
	res.x = point.x + vec.x;
	res.y = point.y + vec.y;
	res.z = point.z + vec.z;
	res.w = point.w + vec.w;
	return (res);
}

/* 
a ← dot(ray.direction, ray.direction)
b ← 2 * dot(ray.direction, sphere_to_ray)
c ← dot(sphere_to_ray, sphere_to_ray) - 1
discriminant ← b² - 4 * a * c 
*/

t_hit	calculate_discriminant(t_ray ray, t_element elem)
{

	float a;
	float b;
	float c;
	float dis;
	int		t[2];


	a = dot_product(ray.vec, ray.vec);
	b = 2 * dot_product(ray.vec, rest_coord(ray.origin, elem.pos));
	c = dot(rest_coord(ray.origin, elem.pos), rest_coord(ray.origin, elem.pos)) - 1;
	dis = b * b - 4 * a * c;
	if (dis < 0)
		return ()

}