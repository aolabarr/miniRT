/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:53:52 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/16 17:05:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float determinant_matrix(float *mat)
{
    float	det;
    int		i;

	det = 0;
	i = 0;
    while (i < 4)
    {
        det += mat[i] * cofactor(mat, 0, i);
        i++;
    }
    return (det);
}

float *invert_matrix(float *mat)
{
    float det;
    float *inv;
	float *cofactor_mat;
	float *aux;
    
    det = determinant_matrix(mat);
    if (det == 0)
        return (NULL);
    inv = (float *)calloc(16, sizeof(float));
    if (!inv)
	{
		return (NULL);
	}   
	aux = cofactor_matrix(mat);
    cofactor_mat = transpose_matrix(aux);
	free(aux);
    int i = 0;
    while (i < 16)
    {
        inv[i] = cofactor_mat[i] / det;
        i++;
    }
    return inv;
}

void minor_matrix(float *mat, float *minor, int row, int col)
{
    int i;
	int	mi;
	int	aux[2];
	
	i = 0;
	mi = 0;
    while (i < 4)
    {
        if (i == row)
		{
			i++;
			continue;
		}
		aux[0] = mi;
		aux[1] = i;
		calculate_minor_row(col, minor, mat, aux);
        mi++;
        i++;
    }
}

void	calculate_minor_row(int col, float *minor, float *mat, int *aux)
{
	int i;
	int	j;
	int	mj;
	int mi;
	
	mj = 0;
	j = 0;
	mi = aux[0];
	i = aux[1];
	while (j < 4)
	{
		if (j == col)
		{
			j++;
			continue;
		}  
		minor[mi * 3 + mj] = mat[i * 4 + j];
		mj++;
		j++;
	}
}

float cofactor(float *mat, int row, int col)
{
    float	minor[9];
	float	det;
    
	minor_matrix(mat, minor, row, col);
	det = minor[0] * (minor[4] * minor[8] - minor[5] * minor[7])
        - minor[1] * (minor[3] * minor[8] - minor[5] * minor[6])
        + minor[2] * (minor[3] * minor[7] - minor[4] * minor[6]);
	if ((row + col) % 2 == 0)
		return(det);
	else
		return (-det);
}

float *cofactor_matrix(float *mat)
{
	float	*res;
	int 	i;
    int 	j;

	i = 0;
	res = (float *)calloc(16, sizeof(float));
	if(!res)
		return (NULL);
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
    return (res);
}
