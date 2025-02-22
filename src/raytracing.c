/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:05:48 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 16:10:11 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int raytracing(t_data *scene)
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
