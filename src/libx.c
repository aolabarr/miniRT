/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:22:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/21 12:53:24 by binary           ###   ########.fr       */
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
	t_pos	center;
	t_vec	right;
	t_vec	up;
	t_pos	aux;
	t_vec	world_up;

	hsize = 2 * tan((scene->cam.fov * PI / 180) / 2);
	vsize = hsize / ASPECT_RATIO;
	center = new_lineal_point(scene->cam.pos, scene->cam.vec, 1);
	if (scene->cam.vec.y == 1 || scene->cam.vec.y == -1)
		world_up = (t_vec){0, 0, 1, 0};
	else
		world_up = (t_vec){0, 1, 0, 0};
		
	right = normalize(cross_product(scene->cam.vec, world_up));
	up = normalize(cross_product(right, scene->cam.vec));
	
	// Inferior Izquierda
	aux = new_lineal_point(center, right, -hsize / 2);
	scene->img.canvas[0] = new_lineal_point(aux, up, -vsize / 2);

	// Inferior Derecha
	aux = new_lineal_point(center, right, hsize / 2);
	scene->img.canvas[1] = new_lineal_point(aux, up, -vsize / 2);

	// Superior Izquierda
	aux = new_lineal_point(center, right, -hsize / 2);
	scene->img.canvas[2] = new_lineal_point(aux, up, vsize / 2);

	// Superior Derecha
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
