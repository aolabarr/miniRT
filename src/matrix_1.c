/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:50:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/13 17:19:40 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int is_equal_matrix(float *mat1, float *mat2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!is_equal(mat1[i], mat2[i]))
			return (0);
		i++;
	}
	return(1);
}

float *multiply_matrix(float *mat1, float *mat2)
{
	int i;
	int j;
	int k;
	int size;
	float *res;

	size = 4;
	res = ft_calloc(size * size, sizeof(float));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			k = 0;
			while (k < 4)
			{
				res[i * 4 + j] += mat1[i * 4 + k] * mat2[k * 4 + j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}
