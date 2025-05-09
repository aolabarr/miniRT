/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/09 15:04:54 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	create_scene(t_data *scene)
{
	init_mlx(scene);
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (handle_error(ERR_MALL), EXIT_FAILURE);
	if (!new_window(scene, scene->name))
		return (handle_error(ERR_MALL), EXIT_FAILURE);
	mlx_loop_hook(scene->mlx, render_image, scene);
	mlx_hook(scene->win, DestroyNotify, NoEventMask, handle_close, scene);
	mlx_hook(scene->win, KeyPress, KeyPressMask, handle_key_input, scene);
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
		data->img.ptr = mlx_new_image(data->mlx, WIDTH, data->height);
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
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < data->height)
		{
			put_color_pixel(data, data->img, x, y);
			y++;
		}
		x++;
		printf("\rRendering: %d %%", (int)(((float)x / WIDTH) * 100));
	}
	printf("\nCOMPLETE!\n");
	return (EXIT_SUCCESS);
}
