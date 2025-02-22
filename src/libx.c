/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:22:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 18:22:59 by aolabarr         ###   ########.fr       */
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
	init_canvas(scene);
	scene->name = ft_strdup(MINI_RT);
	return ;
}

void	init_canvas(t_data *scene)
{
	float hsize;
	float vsize;
	t_position	center;
	t_vector	right;
	t_vector	up;
	t_position	aux;

	hsize = 2 * tan((scene->cam.fov * PI / 180) / 2);
	vsize = hsize / ASPECT_RATIO;
	center = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	right = cross_product(scene->cam.vec, (t_vector){0, 1, 0});
	up = cross_product(scene->cam.vec, right);

	aux = new_lineal_point(center, right, - hsize / 2);
	scene->img.canvas[0] = new_lineal_point(aux, up, - vsize / 2);
	aux = new_lineal_point(center, right, hsize / 2);
	scene->img.canvas[1] = new_lineal_point(aux, up, - vsize / 2);
	aux = new_lineal_point(center, right, - hsize / 2);
	scene->img.canvas[2] = new_lineal_point(aux, up, vsize / 2);
	aux = new_lineal_point(center, right, hsize / 2);
	scene->img.canvas[3] = new_lineal_point(aux, up, vsize / 2);
	return ;
}

void	*new_window(t_data *scene, char *title)
{
	scene->win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, title);
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
	scene->name = NULL;
	scene->img.ptr = NULL;
	mlx_destroy_window(scene->mlx, scene->win);
	mlx_destroy_display(scene->mlx);
	free(scene->mlx);
	ft_putstr_fd(ESC_MSG, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}
