/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 11:09:12 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	handle_key_input(int key, t_data *scene)
{
	if (key == XK_Escape || scene->close == 1)
		close_window(scene);
	else if (key == XK_Delete)
		set_initial_zoom(scene);
	else if (key == XK_Left || key == XK_Right)
		set_traslation_move(scene, key);
	else if (key == XK_Up || key == XK_Down)
		set_traslation_move(scene, key);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		set_static_zoom(scene, key);
	if (key != XK_Escape)
		scene->update = 1;
	return (0);
}

void	set_traslation_move(t_data *scene, int key)
{
	(void)scene;
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

void	set_static_zoom(t_data *scene, int key)
{
	float	*dom;
	float	dx;
	float	dy;

	dom = scene->img.domain;
	dx = (dom[1] - dom[0]) * ZOOM_FACTOR;
	dy = (dom[3] - dom[2]) * ZOOM_FACTOR;
	if (key == MINUS_KEY)
	{
		scene->img.domain[0] = dom[0] + dx / 2;
		scene->img.domain[1] = dom[1] - dx / 2;
		scene->img.domain[2] = dom[2] + dy / 2;
		scene->img.domain[3] = dom[3] - dy / 2;
		scene->img.zoom = scene->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == PLUS_KEY)
	{
		scene->img.domain[0] = dom[0] - dx / 2;
		scene->img.domain[1] = dom[1] + dx / 2;
		scene->img.domain[2] = dom[2] - dy / 2;
		scene->img.domain[3] = dom[3] + dy / 2;
		scene->img.zoom = scene->img.zoom * (1 + ZOOM_FACTOR);
	}
	return ;
}
