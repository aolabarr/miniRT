/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:21:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/20 12:51:48 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	is_coord_equal(t_coord a, t_coord b)
{
	if (is_equal(a.x, b.x))
		if (is_equal(a.y, b.y))
			if (is_equal(a.z, b.z))
				if (is_equal(a.w, b.w))
					return (1);
	return (0);
}

t_vec	sum_vector(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.w = a.w + b.w;
	return (res);
}

t_vec	rest_coord(t_coord a, t_coord b)
{
	t_coord	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w - b.w;
	return (res);
}

t_vec	opp_vector(t_vec vec)
{
	t_vec	zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	zero.w = VECTOR;
	return (rest_coord(zero, vec));
}
