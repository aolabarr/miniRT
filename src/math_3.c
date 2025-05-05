/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:33:54 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/02 11:01:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	ft_pow(float num, int pow)
{
	int		i;
	float	res;

	if (pow == 0)
		return (1);
	res = 1;
	i = 0;
	while (i++ < pow)
		res = res * num;
	return (res);
}

int	is_zerovector(t_vec vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0 && vec.z == 0)
		return (1);
	return (0);
}

float	ft_abs(float num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

int	is_zero(float num)
{
	if (ft_abs(num) < EPSILON)
		return (1);
	return (0);
}

int	is_equal(float a, float b)
{
	if (ft_abs(a - b) < EPSILON)
		return (1);
	return (0);
}
