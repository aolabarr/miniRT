/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:46:45 by beiglesi          #+#    #+#             */
/*   Updated: 2025/05/03 10:17:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_scene(t_data *scene)
{
	init_ambient(&scene->amb);
	init_camera(&scene->cam);
	init_light(&scene->lig);
	scene->elem = NULL;
	scene->n_elem = 0;
	scene->has_amb = FALSE;
	scene->has_cam = FALSE;
	scene->has_lig = FALSE;
	scene->world_y = (t_vec){0, 1, 0, 0};
	scene->world_z = (t_vec){0, 0, 1, 0};
}

void	init_ambient(t_ambient *amb)
{
	amb->ratio = 0.0f;
	init_color(&amb->color);
}

void	init_camera(t_camera *cam)
{
	cam->pos.x = 0;
	cam->pos.y = 0;
	cam->pos.z = 0;
	cam->vec.x = 0;
	cam->vec.y = 0;
	cam->vec.z = 1.0;
	cam->fov = 70;
	cam->theta = acos(cam->vec.y);
}

void	init_light(t_light *light)
{
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
	light->bright = 0.0f;
	init_color(&light->color);
}

void	init_color(t_color *color)
{
	color->red = 0;
	color->green = 0;
	color->blue = 0;
}
