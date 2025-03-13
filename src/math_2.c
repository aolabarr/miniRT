/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:43:47 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/12 11:14:29 by binary           ###   ########.fr       */
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

