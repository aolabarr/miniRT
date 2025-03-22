/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:05:48 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/22 21:07:33 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pos calc_pixel_position(int x, int y, t_pos *canvas)
{
	float u;
	float v;
	t_pos	pixel_pos;
	t_pos	aux[4];

	u = 1.0 - ((float)x / (float)(WIDTH - 1));
	v = 1.0 - ((float)y / (float)(HEIGHT - 1));
	aux[0] = scalar_product(canvas[1], (1 - u) * (1 - v));
	aux[1] = scalar_product(canvas[0], u * (1 - v));
	aux[2] = scalar_product(canvas[3], (1 - u) * v);
	aux[3] = scalar_product(canvas[2], u * v);
	pixel_pos.x = aux[0].x + aux[1].x + aux[2].x + aux[3].x;
	pixel_pos.y = aux[0].y + aux[1].y + aux[2].y + aux[3].y;
	pixel_pos.z = aux[0].z + aux[1].z + aux[2].z + aux[3].z;
	pixel_pos.w = 1;
	return (pixel_pos);
}
void	ray_transform_to_local(t_element elem, t_ray ray, t_ray ray_local)
{
	(void)ray;
	(void)ray_local;
	(void)elem;
	/*
	// traslación inversa + rotación inversa + escalado inverso

	t_ray local_ray;
	float mat1[16], *mat2, mat3[16];

	translation_matrix(elem.pos, mat1);
	invert_matrix(mat1, mat2);
	mat2 = scale_matrix(1 / elem.radio, 1 / elem.radio, 1 / elem.radio);
	mat3 = multiply_matrix()
	*/
}

