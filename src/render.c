/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/17 14:12:52 by beiglesi         ###   ########.fr       */
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
	// printf("\ntr_mat"), print_matrix(data->elem[0].tr_mat), printf("\n");
	// printf("\ntri_mat"), print_matrix(data->elem[0].tri_mat), printf("\n");
	// printf("\ntr_mat"), print_matrix(data->elem[1].tr_mat), printf("\n");
	// printf("\ntri_mat"), print_matrix(data->elem[1].tri_mat), printf("\n");
	// printf("\ntr_mat"), print_matrix(data->elem[2].tr_mat), printf("\n");
	// printf("\ntri_mat"), print_matrix(data->elem[2].tri_mat), printf("\n");
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
	
	t_ray	ray;
	t_hit	hit;
	t_hit	*inters;
	t_color color;
	t_comps comps;
	t_color amb_all;
	t_color lig_all;
	t_color res_color;

	amb_all = mult_color_scalar(scene->amb.color, scene->amb.ratio);
	lig_all = mult_color_scalar(scene->lig.color, scene->lig.bright);
	init_pong_parameters(scene);
	ray = create_ray(scene, img, x, y);
	inters = intersect_world(ray, scene);
	hit = find_hit(scene, inters);
	if (hit.hit == false)
		color = SKY_GREY;
	else
	{
		comps = prepare_computations(hit, ray);
		res_color = hadamard_product(add_colors(amb_all,lig_all), comps.elem.color);
		color = add_color_intensity(res_color, shade_hit(scene, comps));

	}
	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);

}

