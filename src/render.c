/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/12 13:00:31 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	render_image(t_data *data)
{
	if (data->close == 1)
		close_window(data);
	else if (data->update == 1)
	{
		if (data->img.ptr)
			mlx_destroy_image(data->mlx, data->img.ptr);
		data->img.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.ptr,
				&data->img.bpp,
				&data->img.line_len,
				&data->img.endian);
		if (create_image(data) == ERR_MALL)
			return (ERR_MALL);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
		data->update = 0;
	}
	return (0);
}

int	create_image(t_data *data)
{
	int	x;
	int	y;

	//x = 1;
	x = 0;
	while (x < WIDTH)
	{
		//y = 1;
		y = 0;
		// printf("x = %d, y = %d\n", x, y);
		while (y < HEIGHT)
		{
			put_color_pixel(data, data->img, x, y);
			// printf("Dibujando píxel en x: %d, y: %d\n", x, y);
			y++;
		}
		x++;
		// printf("Nuevo x: %d\n", x);
	}
	return (0);
}

// void	put_color_pixel(t_data *data, t_image img, int x, int y)
// {
// 	int	offset;
// 	(void)data;
// 	offset = (img.line_len * y) + x * (img.bpp / 8);
// 	int amb_color = rgb_to_hex(data->amb.color);
// 	int lig_color = rgb_to_hex(data->lig.color);
	
// 	if (x > 200 && x < 400)
// 		*(int *)((char *)img.addr + offset) = amb_color;
// 	else
// 		*(int *)((char *)img.addr + offset) = lig_color;
	
// 	return ;
	
// }

void	put_color_pixel(t_data *data, t_image img, int x, int y)
{
	int	offset;
	t_ray	ray;
	t_hit	hit;
	t_coord	pixel_pos;
	float	pixel_size;
	float	half_width = WIDTH / 2;
	float	half_height = HEIGHT / 2;

	float aspect_ratio = (float)WIDTH / (float)HEIGHT;
	float fov_radians = (data->cam.fov * PI) / 180.0;
	pixel_size = tanf(fov_radians / 2.0) * 2.0 / WIDTH;


	t_color	bg_color = {0, 0, 0};        // Negro para el fondo
	t_color color;

	// Tamaño de cada píxel en el espacio de la cámara
	//pixel_size = data->cam.fov / WIDTH; // cuanto espacio en el mundo 3D ocupa un solo píxel

	// Convertir coordenadas del píxel a coordenadas en la "pared"
	//printf("ANTES x: %d, half_width: %f, resultado: %f\n", x, half_width, (x - half_width));
	// printf("x es: %d\n", x);
	// printf("Dibujando píxel en x: %d, y: %d\n", x, y);
	pixel_pos.x = (x - half_width) * pixel_size * aspect_ratio;
	
	pixel_pos.y = (half_height - y) * pixel_size;
	pixel_pos.z = 1; // La pared está delante de la cámara
	// printf("Pixel Pos X: %f, Y: %f, Z: %f\n", pixel_pos.x, pixel_pos.y, pixel_pos.z);
	// printf(" DESPUES x: %d, half_width: %f, result: %f\n", x, half_width, (x - half_width));

	// Crear rayo desde la cámara hacia el píxel
	ray.origin = data->cam.pos;
	ray.vec = normalize(rest_coord(pixel_pos, data->cam.pos));
	// printf("ray normalized X: %f\n", ray.vec.x);
	// printf("ray normalized Y: %f\n", ray.vec.y);
	// printf("ray normalized Z: %f\n", ray.vec.z);
	// printf("ray normalized W: %d\n", ray.vec.w);
	

	// Verificar intersección con la esfera
	hit = calculate_hit(ray, data->elem[0]);
	
	// Calcular el color a pintar
	if (hit.hit && (hit.t1 > EPSILON || hit.t2 > EPSILON))
	{
		if (hit.t1 < hit.t2)
			color = data->elem[0].color;
		else
			color = bg_color;
	}
	else 
		color = bg_color;
	// Escribir el color en la imagen
	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
}
