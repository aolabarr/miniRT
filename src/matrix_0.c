/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:53:52 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 10:44:49 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	invert_matrix(float *mat, float *inv)
{
	float	det;
	float	aux[16];
	int		i;

	det = determinant_matrix(mat);
	if (ft_abs(det) < EPSILON)
		return (1);
	cofactor_matrix(mat, aux);
	transpose_matrix(aux, inv);
	i = 0;
	while (i < 16)
	{
		inv[i] = inv[i] / det;
		i++;
	}
	return (0);
}

void	cofactor_matrix(float *mat, float *res)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i * 4 + j] = cofactor(mat, i, j);
			j++;
		}
		i++;
	}
	return ;
}

float	cofactor(float *mat, int row, int col)
{
	float	minor[9];
	float	det;

	minor_matrix(mat, minor, row, col);
	det = minor[0] * (minor[4] * minor[8] - minor[5] * minor[7])
		- minor[1] * (minor[3] * minor[8] - minor[5] * minor[6])
		+ minor[2] * (minor[3] * minor[7] - minor[4] * minor[6]);
	if ((row + col) % 2 == 0)
		return (det);
	else
		return (-det);
}

void	minor_matrix(float *mat, float *minor, int row, int col)
{
	int	i;
	int	mi;
	int	aux[2];

	i = 0;
	mi = 0;
	while (i < 4)
	{
		if (i == row)
		{
			i++;
			continue ;
		}
		aux[0] = mi;
		aux[1] = i;
		calculate_minor_row(col, minor, mat, aux);
		mi++;
		i++;
	}
	return ;
}

void	calculate_minor_row(int col, float *minor, float *mat, int *aux)
{
	int	i;
	int	j;
	int	mj;
	int	mi;

	mj = 0;
	j = 0;
	mi = aux[0];
	i = aux[1];
	while (j < 4)
	{
		if (j == col)
		{
			j++;
			continue ;
		}
		minor[mi * 3 + mj] = mat[i * 4 + j];
		mj++;
		j++;
	}
	return ;
}
