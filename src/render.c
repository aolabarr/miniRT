/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/16 13:40:48 by beiglesi         ###   ########.fr       */
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
	t_color	bg_color = {0, 0, 0};        
	t_color color;
		

	float u = x / (WIDTH - 1);
	float v = y / (HEIGHT - 1);

	// pixel_pos.x = (1 - u) * data->img.canvas[0].x + u * data->img.canvas[1].x + (1 - v) * data->img.canvas[0].x + v * data->img.canvas[2].x;
	// pixel_pos.y = (1 - u) * data->img.canvas[0].y + u * data->img.canvas[1].y + (1 - v) * data->img.canvas[0].y + v * data->img.canvas[2].y;
	// pixel_pos.z = (1 - u) * data->img.canvas[0].z + u * data->img.canvas[1].z + (1 - v) * data->img.canvas[0].z + v * data->img.canvas[2].z;

	pixel_pos = sum_coord( \
				sum_coord(mult_coord_float(data->img.canvas[0], (1 - u) * (1 - v)), mult_coord_float(data->img.canvas[1], u * (1 - v))), \
				sum_coord(mult_coord_float(data->img.canvas[2], (1 - u) * v), mult_coord_float(data->img.canvas[3], u * v)));


	// printf("Pixel pos: %f %f %f\n", pixel_pos.x, pixel_pos.y, pixel_pos.z);

	ray.origin = data->cam.pos;
	ray.vec = normalize(rest_coord(pixel_pos, data->cam.pos));
	// printf("Ray origin: %f %f %f\n", ray.origin.x, ray.origin.y, ray.origin.z);
	// printf("Ray vec: %f %f %f\n", ray.vec.x, ray.vec.y, ray.vec.z);
	
	hit = calculate_hit(ray, data->elem[0]);
	
	if (hit.hit && (hit.t1 > EPSILON || hit.t2 > EPSILON))
	{
		if (hit.t1 < hit.t2)
			color = data->elem[0].color;
		else
			color = bg_color;
	}
	else 
		color = bg_color;

	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
}
