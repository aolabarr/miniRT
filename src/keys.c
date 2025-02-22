/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/20 18:04:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	handle_key_input(int key, t_data *data)
{
	if (key == XK_Escape || data->close == 1)
		close_window(data);
	else if (key == XK_Delete)
		set_initial_zoom(data);
	else if (key == XK_Left || key == XK_Right)
		set_traslation_move(data, key);
	else if (key == XK_Up || key == XK_Down)
		set_traslation_move(data, key);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		set_static_zoom(data, key);
	if (key != XK_Escape)
		data->update = 1;
	return (0);
}

void	set_traslation_move(t_data *data, int key)
{
	if (key == XK_Left)
	{
		printf("press left\n");
	}
	else if (key == XK_Right)
	{
		printf("press right\n");
	}
	else if (key == XK_Up)
	{
		printf("press up\n");
	}
	else if (key == XK_Down)
	{
		printf("press down\n");
	}
	return ;
}

void	set_static_zoom(t_data *data, int key)
{
	float	*dom;
	float	dx;
	float	dy;

	dom = data->img.domain;
	dx = (dom[1] - dom[0]) * ZOOM_FACTOR;
	dy = (dom[3] - dom[2]) * ZOOM_FACTOR;
	if (key == MINUS_KEY)
	{
		data->img.domain[0] = dom[0] + dx / 2;
		data->img.domain[1] = dom[1] - dx / 2;
		data->img.domain[2] = dom[2] + dy / 2;
		data->img.domain[3] = dom[3] - dy / 2;
		data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == PLUS_KEY)
	{
		data->img.domain[0] = dom[0] - dx / 2;
		data->img.domain[1] = dom[1] + dx / 2;
		data->img.domain[2] = dom[2] - dy / 2;
		data->img.domain[3] = dom[3] + dy / 2;
		data->img.zoom = data->img.zoom * (1 + ZOOM_FACTOR);
	}
	return ;
}
