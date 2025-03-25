/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:50:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/25 21:31:30 by aolabarr         ###   ########.fr       */
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

	ft_memsetf(res, 0, 16);
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

void	multiply_matrix_vector(float *mat, t_vec vector, t_vec *res)
{
    int		i;
	int		j;
	float   vec[4];
	float   result[4];

	init_coordf(result);
	vec[0] = vector.x;
	vec[1] = vector.y;
	vec[2] = vector.z;
	vec[3] = vector.w;
	i = 0;
	while (i < 4)
    {
		j = 0;
		while(j < 4)
        {
            result[i] += mat[i * 4 + j] * vec[j];
			j++;
        }
		i++;
    }
	res->x = result[0];
	res->y = result[1];
	res->z = result[2];
	res->w = VECTOR;
    return;
}

void	multiply_matrix_pos(float *mat, t_pos point, t_pos *res)
{
    int		i;
	int		j;
	float   pos[4];
	float   result[4];

	init_coordf(result);
	pos[0] = point.x;
	pos[1] = point.y;
	pos[2] = point.z;
	pos[3] = point.w;
	i = 0;
	while (i < 4)
    {
		j = 0;
		while(j < 4)
        {
            result[i] += mat[i * 4 + j] * pos[j];
			j++;
        }
		i++;
    }
	res->x = result[0];
	res->y = result[1];
	res->z = result[2];
	res->w = POINT;
    return;
}

void init_coordf(float *coord)
{
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	coord[3] = 0;
	return ;
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
