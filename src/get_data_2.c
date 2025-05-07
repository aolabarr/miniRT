/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:22:22 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 14:14:49 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	add_element(t_data *scene, t_element *new_elem)
{
	t_element	*new_array;
	int			i;

	i = 0;
	new_array = malloc(sizeof(t_element) * (scene->n_elem + 1));
	if (!new_array)
		return (handle_error(ERR_MALL), EXIT_FAILURE);
	while (i < scene->n_elem)
	{
		new_array[i] = scene->elem[i];
		i++;
	}
	new_array[scene->n_elem] = *new_elem;
	if (scene->elem)
		free(scene->elem);
	scene->elem = new_array;
	scene->n_elem++;
	return (EXIT_SUCCESS);
}

int	get_color(char *str, t_color *color)
{
	char	**temp;
	int		rgb[3];

	temp = ft_split(str, ',');
	if (!temp || len_mat(temp) != 3)
		return (ft_free_mat(temp), ERR_INT);
	rgb[0] = ft_atoi(temp[0]);
	if (rgb[0] < MIN_RGB || rgb[0] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	rgb[1] = ft_atoi(temp[1]);
	if (rgb[1] < MIN_RGB || rgb[1] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	rgb[2] = ft_atoi(temp[2]);
	if (rgb[2] < MIN_RGB || rgb[2] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	color->red = rgb[0] / 255.0f;
	color->green = rgb[1] / 255.0f;
	color->blue = rgb[2] / 255.0f;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}
