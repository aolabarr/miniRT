/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:50:20 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 11:01:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	copy_coord_to_array(vector, vec);
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
	copy_coord_to_array(point, pos);
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

void copy_coord_to_array(t_coord coord, float *array)
{
	array[0] = coord.x;
	array[1] = coord.y;
	array[2] = coord.z;
	array[3] = coord.w;
	return ;
}

