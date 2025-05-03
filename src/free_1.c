/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:11:25 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 09:56:07 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	if (scene && scene->elem)
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

void	free_scene_first(t_data *scene)
{
	int i;

	i = 0;
	if (scene && scene->elem)
	{
		while (i < scene->n_elem)
		{
			i++;
		}
		free(scene->elem);
		scene->elem = NULL;
	}
}

char	**ft_free_mat_n(char **mat, size_t mlen)
{
	while (mlen)
	{
		free(mat[mlen]);
		mlen--;
	}
	free(mat[0]);
	free(mat);
	return (NULL);
}

