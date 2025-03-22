/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/22 17:57:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int create_scene(t_data *scene)
{
	init_mlx(scene);
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (handle_error(ERR_MALL),EXIT_FAILURE);
	if (!new_window(scene, scene->name))
		return (handle_error(ERR_MALL),EXIT_FAILURE);
	mlx_loop_hook(scene->mlx, render_image, scene);
	mlx_hook(scene->win, DestroyNotify, NoEventMask, handle_close, scene);
	mlx_hook(scene->win, KeyPress, KeyPressMask, handle_key_input, scene);
	//mlx_hook(scene->win, ButtonPress, ButtonPressMask, handle_scroll, scene);
	//mlx_hook(scene->win, MotionNotify, PointerMotionMask, mouse_move, scene);
	mlx_loop(scene->mlx);
	return (EXIT_SUCCESS);
}

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

void	put_color_pixel(t_data *data, t_image img, int x, int y)
{
	int	offset;
	t_pos	pixel_pos;
	t_ray	ray;
	//t_ray	local_ray;
	t_hit	hit;
	t_color color;
	
	t_color	bg_color = {0, 0, 0};        
	
	pixel_pos = calc_pixel_position(x, y, img.canvas);
	ray.origin = data->cam.pos;
	ray.vec = normalize(rest_coord(pixel_pos, data->cam.pos));
	//local_ray = ray_transform(ray, data->elem[0]);



	hit = calculate_hit(ray, data->elem[0]);
	
	if (hit.hit && (hit.t1 > EPSILON || hit.t2 > EPSILON))
	{
		if (hit.t1 < hit.t2 || hit.t2 < hit.t1)
			color = data->elem[0].color;
		else
			color = bg_color;
	}
	else 
		color = bg_color;

	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
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

/* 
INTERPOLACIÓN BILINEAL DE PUNTO EN EL CANVAS
pixel_pos.x = (1 - u) * (1 - v) * canvas[0].x +
              u * (1 - v) * canvas[1].x +
              (1 - u) * v * canvas[2].x +
              u * v * canvas[3].x;

pixel_pos.y = (1 - u) * (1 - v) * canvas[0].y +
              u * (1 - v) * canvas[1].y +
              (1 - u) * v * canvas[2].y +
              u * v * canvas[3].y;

pixel_pos.z = (1 - u) * (1 - v) * canvas[0].z +
              u * (1 - v) * canvas[1].z +
              (1 - u) * v * canvas[2].z +
              u * v * canvas[3].z;
*/
