/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:43:47 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/26 12:58:13 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float magnitude(t_vec vec)
{
	float res;

	res = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
	return (res);
}

t_vec normalize(t_vec vec)
{
	float mag;
	t_vec res;

	mag = magnitude(vec);
	res.x = vec.x / mag;
	res.y = vec.y / mag;
	res.z = vec.z / mag;
	//res.w = vec.w / mag;
	res.w = 0;
	return (res);
}

float dot_product(t_vec a, t_vec b)
{
	float res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

t_pos	sum_coord(t_pos coord1, t_pos coord2)
{
	t_pos	res;

	res.x = coord1.x + coord2.x;
	res.y = coord1.y + coord2.y;
	res.z = coord1.z + coord2.z;
	res.w = 1;
	return (res);
}

t_pos	mult_coord_float(t_pos coord1, float t)
{
	t_pos	res;

	res.x = coord1.x * t;
	res.y = coord1.y * t;
	res.z = coord1.z * t;
	res.w = 1;
	return (res);
}

int is_zerovector(t_vec vec)
{
	if(vec.x == 0 && vec.y == 0 && vec.z == 0 && vec.z == 0)
		return (1);
	return (0);
}
