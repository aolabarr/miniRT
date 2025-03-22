/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:50:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/22 21:08:38 by aolabarr         ###   ########.fr       */
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

void	multiply_matrix(float *mat1, float *mat2, float *res)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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
	return;
}

void	multiply_matrix_vector(float *mat, float *vec, float *res)
{
    int		i;
	int		j;

	i = 0;
	while (i < 4)
    {
		j = 0;
		while(j < 4)
        {
            res[i] += mat[i * 4 + j] * vec[j];
			j++;
        }
		i++;
    }
    return;
}

void	identity_matrix(float *mat)
{
    int i;

	i = 0;
	while(i < 4)
	{
		mat[i * 4 + i] = 1;
		i++;
	} 
    return;
}
void	transpose_matrix(float *mat, float *res)
{
    int		i;
	int		j;
   
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
    return;
}
