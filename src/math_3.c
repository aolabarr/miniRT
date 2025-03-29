/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:33:54 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/29 16:09:52 by aolabarr         ###   ########.fr       */
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
