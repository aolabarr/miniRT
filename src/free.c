/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:11:25 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/18 09:29:54 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void handle_free(t_data *scene)
{
	free_scene(scene);
}

void	ft_free_v(void *str)
{
	if (str)
		free(str);
	return ;
}

void	ft_free_mat(char **mat)
{
	int i;

	i = 0;
	if (!mat)
		return ;
	while(mat[i])
	{
		if (mat[i])
			free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
	return ;
}

void	free_scene(t_data *scene)
{
	int i;

	i = 0;
	if (scene->elem)
	{
		while (i < scene->n_elem)
		{
			free(scene->elem[i].tr_mat);
			free(scene->elem[i].tri_mat);
			i++;
		}
		free(scene->elem);
		scene->elem = NULL;
	}
}
