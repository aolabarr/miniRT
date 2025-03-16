/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:21:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/16 11:44:46 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float myabs(float num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

int is_equal(float a, float b)
{
    if (myabs(a - b) < EPSILON)
		return(1);
	return (0);
}
int is_coord_equal(t_coord a, t_coord b)
{
	if (is_equal(a.x, b.x))
		if (is_equal(a.y, b.y))
			if (is_equal(a.z, b.z))
				if (is_equal(a.w, b.w))
					return (1);
	return (0);
}

t_vec sum_vector(t_vec a, t_vec b)
{
 	t_vec res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.w = a.w + b.w;
	return(res);
}

t_vec rest_coord(t_coord a, t_coord b)
{
 	t_coord res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w - b.w;
	return(res);
}
t_vec opp_vector(t_vec vec)
{
	t_vec zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	zero.w = 0;
	return(rest_coord(zero, vec));
}

t_vec scalar_product(t_vec vec, float scalar)
{
    t_vec res;

    res.x = vec.x * scalar;
    res.y = vec.y * scalar;
    res.z = vec.z * scalar;
	res.w = vec.w * scalar;
    return (res);
}
t_vec cross_product(t_vec v1, t_vec v2)
{
    t_vec res;

    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
	res.w = 0;
    return (res);
}

t_pos  new_lineal_point(t_pos origin, t_vec vector, float t)
{
    t_pos res;

    res.x = origin.x + t * vector.x;
    res.y = origin.y + t * vector.y;
    res.z = origin.z + t * vector.z;
    return(res);
}

