/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/29 11:17:30 by beiglesi         ###   ########.fr       */
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

	if (init_trans_matrix(data))
		return (EXIT_FAILURE);
	printf("\ntr_mat"), print_matrix(data->elem->tr_mat), printf("\n");
	printf("\ntri_mat"), print_matrix(data->elem->tri_mat), printf("\n");
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			put_color_pixel(data, data->img, x, y);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

void	put_color_pixel(t_data *scene, t_image img, int x, int y)
{
	int	offset;
	t_pos	pixel_pos;
	t_ray	ray;
	t_ray	local_ray;
	t_hit	hit;
	t_pos	hit_point;
	t_vec	normal, reflect;
	t_color color;
	
	t_color	bg_color = {0, 0, 0};        
	
	pixel_pos = calc_pixel_position(x, y, img.canvas);
	ray.origin = scene->cam.pos;
	ray.vec = normalize(rest_coord(pixel_pos, scene->cam.pos));

	//printf(" cam pos: "), print_pos(scene->cam.pos);
	//print_ray(ray);

	ray_transform_to_local(&scene->elem[0], ray, &local_ray);
	hit = sphere_intersection(local_ray, scene->elem[0]);
	hit_point =	get_hit_point(ray, hit);
	normal = normal_at(scene->elem[0], hit_point);
	reflect = reflect_at(ray.vec, normal);
	//printf("Normal\n"), print_vector(normal);
	//printf("Reflec\n"), print_vector(reflect);


	if (hit.hit && (hit.t1 > EPSILON || hit.t2 > EPSILON))
	{
		if (hit.t1 < hit.t2 || hit.t2 < hit.t1)
			color = scene->elem[0].color;
		else
			color = bg_color;
	}
	else 
		color = bg_color;

	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
}

/* PARA BORRAR ES SOLO CHECKEO DEL PLANO*/

// void	put_color_pixel(t_data *data, t_image img, int x, int y)
// {
// 	int	offset;
// 	t_ray	ray;
// 	t_hit	hit;
// 	t_hit	hitplane;
// 	t_coord	pixel_pos;
// 	t_color	bg_color = {0, 0, 0};        
// 	t_color color;
		

// 	float u = 1.0 - ((float)x / (float)(WIDTH - 1));
// 	float v = 1.0 - ((float)y / (float)(HEIGHT - 1));

// 	t_pos aux1 = scalar_product(data->img.canvas[1], (1 - u) * (1 - v));
// 	t_pos aux2 = scalar_product(data->img.canvas[0], u * (1 - v));
// 	t_pos aux3 = scalar_product(data->img.canvas[3], (1 - u) * v);
// 	t_pos aux4 = scalar_product(data->img.canvas[2], u * v);

// 	pixel_pos.x = aux1.x + aux2.x + aux3.x + aux4.x;
// 	pixel_pos.y = aux1.y + aux2.y + aux3.y + aux4.y;
// 	pixel_pos.z = aux1.z + aux2.z + aux3.z + aux4.z;
// 	pixel_pos.w = 1;


// 	// pixel_pos = sum_coord( \
// 	// 			sum_coord(mult_coord_float(data->img.canvas[0], (1 - u) * (1 - v)), \
// 	// 					mult_coord_float(data->img.canvas[1], u * (1 - v))), \
// 	// 			sum_coord(mult_coord_float(data->img.canvas[2], (1 - u) * v), \
// 	// 					mult_coord_float(data->img.canvas[3], u * v)));

// 	ray.origin = data->cam.pos;
// 	ray.vec = normalize(rest_coord(pixel_pos, data->cam.pos));
	
// 	hit = sphere_intersection(ray, data->elem[0]);
	
// 	hitplane = plane_intersection(ray, data->elem[1]);
// 	// if (hitplane.hit == true)
// 	// {
// 	// 	color = data->elem[1].color;
// 	// }
// 	if (hit.hit && (!hitplane.hit || hit.t1 < hitplane.t1))
// 		color = data->elem[0].color;
// 	else if (hitplane.hit)
// 		color = data->elem[1].color; 
// 	else
// 		color = bg_color;
// 	// if (hit.hit && (hit.t1 > EPSILON || hit.t2 > EPSILON))
// 	// {
// 	// 	if (hit.t1 < hit.t2 || hit.t2 < hit.t1)
// 	// 		color = data->elem[0].color;
	
// 	// 	else
// 	// 		color = bg_color;
// 	// }
// 	// else 
// 	// 	color = bg_color;

// 	offset = (img.line_len * y) + x * (img.bpp / 8);
// 	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
// }
