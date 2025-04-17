/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/14 21:10:38 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	handle_key_input(int key, t_data *scene)
{
	if (key == XK_Escape || scene->close == 1)
		close_window(scene);
	// else if (key == XK_Delete)
		// init_canvas(scene);
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
	t_pos from;
	t_pos to;
	t_vec world_up;
	t_vec rigth_up[2];
	(void) from;
	(void) to;
	from = scene->cam.pos;
	to = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	if(is_equal(scene->cam.vec.y, 1.0) || is_equal(scene->cam.vec.y, -1.0))
		world_up = WORLD_Z;
	else
		world_up = WORLD_Y;
	rigth_up[0] = normalize(cross_product(scene->cam.vec, world_up));
	rigth_up[1] = normalize(cross_product(rigth_up[0], scene->cam.vec));

	if (key == XK_Left)
	{
		printf("press left\n");
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[0], -DELTA_TRANS);
	}
	else if (key == XK_Right)
	{
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[0], DELTA_TRANS);
		printf("press right\n");
	}
	else if (key == XK_Up)
	{
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[1], DELTA_TRANS);
		printf("press up\n");
	}
	else if (key == XK_Down)
	{
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[1], -DELTA_TRANS);
		printf("press down\n");
	}
	return ;
}

void	set_static_zoom(t_data *scene, int key)
{
	if (key == MINUS_KEY)
	{
		scene->cam.pos = new_lineal_point(scene->cam.pos, scene->cam.vec, DELTA_TRANS);
		printf("press minus\n");
	}
	else if (key == PLUS_KEY)
	{
		scene->cam.pos = new_lineal_point(scene->cam.pos, scene->cam.vec, -DELTA_TRANS);
		printf("press plus\n");
	}
	return ;
}
