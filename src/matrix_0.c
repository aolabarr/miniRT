/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:08:18 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/22 21:07:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float *create_matrix(float a1,float a2,float a3,float a4,
    float a5,float a6,float a7,float a8,
    float a9,float a10,float a11,float a12,
    float a13,float a14,float a15,float a16)
{
    float *mat;

    mat = malloc(16 * sizeof(float));
    if (!mat)
        return(mat);
    mat[0] = a1, mat[1] = a2, mat[2] = a3, mat[3] = a4;
    mat[4] = a5, mat[5] = a6, mat[6] = a7, mat[7] = a8;
    mat[8] = a9, mat[9] = a10, mat[10] = a11, mat[11] = a12;
    mat[12] = a13, mat[13] = a14, mat[14] = a15, mat[15] = a16;
    return (mat);
}

void print_matrix(float *mat)
{
    printf("\n%.2f\t%.4f\t%.2f\t%.2f\n", mat[0], mat[1], mat[2], mat[3]);
    printf("%.2f\t%.2f\t%.2f\t%.2f\n", mat[4], mat[5], mat[6], mat[7]);
    printf("%.2f\t%.2f\t%.2f\t%.2f\n", mat[8], mat[9], mat[10], mat[11]);
    printf("%.2f\t%.2f\t%.2f\t%.2f\n", mat[12], mat[13], mat[14], mat[15]);
}
void print_matrix_4f(float *mat)
{
    printf("\n%.4f\t%.4f\t%.4f\t%.4f\n", mat[0], mat[1], mat[2], mat[3]);
    printf("%.4f\t%.4f\t%.4f\t%.4f\n", mat[4], mat[5], mat[6], mat[7]);
    printf("%.4f\t%.4f\t%.4f\t%.4f\n", mat[8], mat[9], mat[10], mat[11]);
    printf("%.4f\t%.4f\t%.4f\t%.4f\n", mat[12], mat[13], mat[14], mat[15]);
}

void print_vector(float *vec)
{
    printf("\n%.2f\t%.2f\t%.2f\t%.2f\n", vec[0], vec[1], vec[2], vec[3]);
}
