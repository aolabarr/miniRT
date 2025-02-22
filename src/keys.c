/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 18:27:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	handle_key_input(int key, t_data *scene)
{
	if (key == XK_Escape || scene->close == 1)
		close_window(scene);
	else if (key == XK_Delete)
		init_canvas(scene);
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
	(void)scene;
	if (key == MINUS_KEY)
	{
		printf("press minus\n");
	}
	else if (key == PLUS_KEY)
	{
		printf("press plus\n");
	}
	return ;
}
