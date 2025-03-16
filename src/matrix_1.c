/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:50:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/16 13:15:36 by aolabarr         ###   ########.fr       */
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

float *multiply_matrix_vector(float *mat, float *vec)
{
    int		i;
	int		j;
	int		size;
    float	*res;

	size = 4;
    res = (float *)calloc(size, sizeof(float));
    if (!res)
		return (NULL);
	i = 0;
	while (i < size)
    {
		j = 0;
		while(j < size)
        {
            res[i] += mat[i * 4 + j] * vec[j];
			j++;
        }
		i++;
    }
    return (res);
}

float *identity_matrix()
{
    int i;
    float *mat;

    mat = (float *)calloc(16, sizeof(float));
    if (!mat)
	{
		return (NULL);
	}   
	i = 0;
	while(i < 4)
	{
		mat[i * 4 + i] = 1;
		i++;
	}
        
    return (mat);
}
float *transpose_matrix(float *mat)
{
    int		i;
	int		j;
    float	*res;

    res = (float *)calloc(16, sizeof(float));
	i = 0;
    if (!res)
        return (NULL);
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
    return (res);
}
