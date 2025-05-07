/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:53:16 by binary            #+#    #+#             */
/*   Updated: 2025/05/05 21:53:20 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec	scalar_product(t_vec vec, float scalar)
{
	t_vec	res;

	res.x = vec.x * scalar;
	res.y = vec.y * scalar;
	res.z = vec.z * scalar;
	res.w = VECTOR;
	return (res);
}

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	res.w = VECTOR;
	return (res);
}

t_pos	new_lineal_point(t_pos origin, t_vec vector, float t)
{
	t_pos	res;

	res.x = origin.x + t * vector.x;
	res.y = origin.y + t * vector.y;
	res.z = origin.z + t * vector.z;
	res.w = POINT;
	return (res);
}

t_pos	zero_pos(void)
{
	t_pos	zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	zero.w = POINT;
	return (zero);
}
