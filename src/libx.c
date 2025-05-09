/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:22:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/09 15:03:02 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_mlx(t_data *scene)
{
	scene->mlx = NULL;
	scene->win = NULL;
	scene->close = 0;
	scene->img.ptr = NULL;
	scene->img.addr = NULL;
	scene->img.bpp = 0;
	scene->img.line_len = 0;
	scene->img.endian = 0;
	scene->update = 1;
	scene->aspect_ratio = (float)ASPECT_1 / (float)ASPECT_2;
	scene->height = (float)WIDTH / scene->aspect_ratio;
	init_canvas(scene);
	scene->name = ft_strdup(MINI_RT);
	return ;
}

void	*new_window(t_data *scene, char *title)
{
	scene->win = mlx_new_window(scene->mlx, WIDTH, scene->height, title);
	if (!scene->win)
	{
		mlx_destroy_display(scene->mlx);
		ft_free_v(scene->mlx);
		return (NULL);
	}
	return (scene->win);
}

int	handle_close(t_data *scene)
{
	scene->close = 1;
	return (0);
}

int	close_window(t_data *scene)
{
	if (scene->img.ptr)
		mlx_destroy_image(scene->mlx, scene->img.ptr);
	if (scene->name)
		ft_free(scene->name);
	scene->name = NULL;
	scene->img.ptr = NULL;
	mlx_destroy_window(scene->mlx, scene->win);
	mlx_destroy_display(scene->mlx);
	free(scene->mlx);
	free_scene(scene);
	ft_putstr_fd(ESC_MSG, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}
