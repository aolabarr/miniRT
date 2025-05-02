/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/02 18:04:23 by aolabarr         ###   ########.fr       */
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
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		set_rotation_move(scene, key);
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
	from = scene->cam.pos;
	to = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	if(is_equal(scene->cam.vec.y, 1.0) || is_equal(scene->cam.vec.y, -1.0))
		world_up = WORLD_Z;
	else
		world_up = WORLD_Y;
	rigth_up[0] = normalize(cross_product(scene->cam.vec, world_up));
	rigth_up[1] = normalize(cross_product(rigth_up[0], scene->cam.vec));
	if (key == XK_Left)
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[0], -DELTA_TRANS);
	else if (key == XK_Right)
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[0], DELTA_TRANS);
	else if (key == XK_Up)
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[1], DELTA_TRANS);
	else if (key == XK_Down)
		scene->cam.pos = new_lineal_point(scene->cam.pos, rigth_up[1], -DELTA_TRANS);
	return ;
}

void	set_static_zoom(t_data *scene, int key)
{
	if (key == MINUS_KEY)
		scene->cam.pos = new_lineal_point(scene->cam.pos, scene->cam.vec, DELTA_TRANS);
	else if (key == PLUS_KEY)
		scene->cam.pos = new_lineal_point(scene->cam.pos, scene->cam.vec, -DELTA_TRANS);
	return ;
}

void	set_rotation_move(t_data *scene, int key)
{
	t_pos from;
	t_pos to;
	//t_vec world_up;
	t_vec rigth_up[2];
	//float theta;

	from = scene->cam.pos;
	to = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);

	/*
	if(is_equal(scene->cam.vec.y, 1.0) || is_equal(scene->cam.vec.y, -1.0))
		world_up = WORLD_Z;
	else
		world_up = WORLD_Y;
	*/
	
	rigth_up[0] = normalize(cross_product(scene->cam.vec, WORLD_Y));
	rigth_up[1] = normalize(cross_product(rigth_up[0], scene->cam.vec));
	//printf("cam: %f, %f, %f\tw_up: %f, %f, %f\n", scene->cam.vec.x, scene->cam.vec.y, scene->cam.vec.z, world_up.x, world_up.y,world_up.z);
	printf("rigth: %f, %f, %f\tup: %f, %f, %f\n", rigth_up[0].x, rigth_up[0].y, rigth_up[0].z, rigth_up[1].x, rigth_up[1].y,rigth_up[1].z);
	set_orientation(scene, key, to, rigth_up);
	init_canvas(scene);
}
void	set_orientation(t_data *scene, int key, t_pos to, t_vec *rigth_up)
{
	t_pos target;
	t_vec targetv;
	float theta;

	if (key == A_KEY)
		target = new_lineal_point(to, opp_vector(rigth_up[0]), DELTA_ROT);
	else if (key == D_KEY)
		target = new_lineal_point(to, rigth_up[0], DELTA_ROT);
	else if (key == W_KEY)
		target = new_lineal_point(to, rigth_up[1], DELTA_ROT);
	else
		target = new_lineal_point(to, opp_vector(rigth_up[1]), DELTA_ROT);
	targetv = normalize(rest_coord(target, scene->cam.pos));
	theta = ft_abs(acos(targetv.y));
	printf("theta: %f\t vec.y: %f\n", theta * 180 / PI, scene->cam.vec.y);
	if (theta < TOL_ANGLE * PI / 180 && !is_equal(theta, scene->cam.theta) && theta < scene->cam.theta)
		return ;
	if (theta > (180 - TOL_ANGLE) * PI / 180 && !is_equal(theta, scene->cam.theta) && theta > scene->cam.theta)
		return ;
	scene->cam.vec = targetv;
	scene->cam.theta = theta;
	printf("new cam: %f, %f, %f\n", scene->cam.vec.x, scene->cam.vec.y,scene->cam.vec.z);
	return ;
}

