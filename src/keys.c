/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:45:43 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/10 12:10:52 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	handle_key_input(int key, t_data *scene)
{
	if (key == XK_Escape || scene->close == 1)
		close_window(scene);
	else if (key == XK_Left || key == XK_Right)
		set_traslation_move(scene, key);
	else if (key == XK_Up || key == XK_Down)
		set_traslation_move(scene, key);
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		set_rotation_move(scene, key);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		set_static_zoom(scene, key);
	if (key == XK_Left || key == XK_Right
		|| key == XK_Up || key == XK_Down || key == PLUS_KEY
		|| key == MINUS_KEY)
		scene->update = 1;
	if ((key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		&& !(vector_isequal(scene->cam.vec, scene->world_y)
			|| vector_isequal(scene->cam.vec, opp_vector(scene->world_y))))
		scene->update = 1;
	return (0);
}

void	set_traslation_move(t_data *sc, int key)
{
	t_vec	world_up;
	t_vec	rigth_up[2];

	if (is_equal(sc->cam.vec.y, 1.0) || is_equal(sc->cam.vec.y, -1.0))
		world_up = sc->world_z;
	else
		world_up = sc->world_y;
	rigth_up[0] = normalize(cross_product(sc->cam.vec, world_up));
	rigth_up[1] = normalize(cross_product(rigth_up[0], sc->cam.vec));
	if (key == XK_Left)
		sc->cam.pos = new_lineal_point(sc->cam.pos, rigth_up[0], -DELTA_TR);
	else if (key == XK_Right)
		sc->cam.pos = new_lineal_point(sc->cam.pos, rigth_up[0], DELTA_TR);
	else if (key == XK_Up)
		sc->cam.pos = new_lineal_point(sc->cam.pos, rigth_up[1], DELTA_TR);
	else if (key == XK_Down)
		sc->cam.pos = new_lineal_point(sc->cam.pos, rigth_up[1], -DELTA_TR);
	init_canvas(sc);
	return ;
}

void	set_static_zoom(t_data *sc, int key)
{
	if (key == MINUS_KEY)
		sc->cam.pos = new_lineal_point(sc->cam.pos, sc->cam.vec, DELTA_TR);
	else if (key == PLUS_KEY)
		sc->cam.pos = new_lineal_point(sc->cam.pos, sc->cam.vec, -DELTA_TR);
	init_canvas(sc);
	return ;
}

void	set_rotation_move(t_data *scene, int key)
{
	t_pos	to;
	t_vec	rigth_up[2];

	if (vector_isequal(scene->cam.vec, scene->world_y)
		|| vector_isequal(scene->cam.vec, opp_vector(scene->world_y)))
		return ;
	to = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	rigth_up[0] = normalize(cross_product(scene->cam.vec, scene->world_y));
	rigth_up[1] = normalize(cross_product(rigth_up[0], scene->cam.vec));
	set_orientation(scene, key, to, rigth_up);
	init_canvas(scene);
}

void	set_orientation(t_data *scene, int key, t_pos to, t_vec *rigth_up)
{
	t_pos	target;
	t_vec	targetv;
	float	theta;

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
	if (theta < TOL_ANGLE * PI / 180 && !is_equal(theta, scene->cam.theta)
		&& theta < scene->cam.theta)
		return ;
	if (theta > (180 - TOL_ANGLE) * PI / 180
		&& !is_equal(theta, scene->cam.theta) && theta > scene->cam.theta)
		return ;
	scene->cam.vec = targetv;
	scene->cam.theta = theta;
	return ;
}
