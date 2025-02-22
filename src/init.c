/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:46:45 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/22 11:09:27 by aolabarr         ###   ########.fr       */
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
}

void	init_ambient(t_ambient *amb)
{
	amb->ratio = 0;
	amb->color = 0xFFFFFF;
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
}

void	init_light(t_light *light)
{
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
	light->bright = 0;
	light->color = 0;
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <  4)
		return (EXIT_FAILURE);
	if (ft_strncmp(str + len - 3, ".rt", 3))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
