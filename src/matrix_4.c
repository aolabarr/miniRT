/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:00:13 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 11:01:16 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	identity_matrix(float *mat)
{
	int	i;

	i = 0;
	ft_memset(mat, 0, 16);
	while (i < 4)
	{
		mat[i * 4 + i] = 1;
		i++;
	}
	return ;
}

void	transpose_matrix(float *mat, float *res)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[j * 4 + i] = mat[i * 4 + j];
			j++;
		}
		i++;
	}
	return ;
}

int	is_equal_matrix(float *mat1, float *mat2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!is_equal(mat1[i], mat2[i]))
			return (0);
		i++;
	}
	return (1);
}
