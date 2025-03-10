/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 18:24:09 by aolabarr         ###   ########.fr       */
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

	x = 1;
	while (x < WIDTH)
	{
		y = 1;
		while (y < HEIGHT)
		{
			put_color_pixel(data, data->img, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

void	put_color_pixel(t_data *data, t_image img, int x, int y)
{
	int	offset;
	(void)data;
	offset = (img.line_len * y) + x * (img.bpp / 8);
	
	if (x > 200 && x < 400)
		*(int *)((char *)img.addr + offset) = data->elem[0].color;
	else
		*(int *)((char *)img.addr + offset) = data->elem[1].color;
	
	return ;
	
}
