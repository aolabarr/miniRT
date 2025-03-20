/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:55 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/20 15:33:41 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float *translation_matrix(float x, float y, float z)
{
    float *mat;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[3] = x;
    mat[7] = y;
    mat[11] = z;
    return (mat);
}

float *scale_matrix(float x, float y, float z)
{
    float *mat;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[0] = x;
    mat[5] = y;
    mat[10] = z;
    return (mat);
}

float *rotation_x_matrix(float angle)
{
    float *mat;

	angle = PI / 180 * angle;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[5] = cos(angle);
    mat[6] = - sin(angle);
    mat[9] = sin(angle);
	mat[10] = cos(angle);
    return (mat);
}

float *rotation_y_matrix(float angle)
{
    float *mat;

	angle = PI / 180 * angle;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[0] = cos(angle);
    mat[2] = sin(angle);
    mat[8] = - sin(angle);
	mat[10] = cos(angle);
    return (mat);
}

float *rotation_z_matrix(float angle)
{
    float *mat;

	angle = PI / 180 * angle;

    mat = identity_matrix();
    if (!mat)
        return (NULL);
    mat[0] = cos(angle);
    mat[1] = - sin(angle);
    mat[4] = sin(angle);
	mat[5] = cos(angle);
    return (mat);
}

