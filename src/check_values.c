/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:21:22 by binary            #+#    #+#             */
/*   Updated: 2025/04/20 12:22:52 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int normalized_vector(t_coord vec)
{
    int norm;

    norm = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (norm == 1)
        return (1);
    return (0);
}

int len_mat(char **str)
{
	int	i;

	if (!str)
        return (0);
    i = 0;
	while (str[i])
        i++;
    return (i);
}

int	get_sphere(char **str, t_element *elem)
{
	if(!str || !elem)
		return (EXIT_FAILURE);
	if (len_mat(str) == 4)
	{
		elem->radio = ft_atoif(str[2]) / (float)2.0;
		if (get_color(str[3], &(elem->color)) == ERR_INT)
			return (EXIT_FAILURE);
		elem->height = 0;
		elem->vec = (t_coord){0,0,0, VECTOR};
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_plane(char **str, t_element *elem)
{
	if(!str || !elem)
		return (EXIT_FAILURE);
	if (len_mat(str) == 4)
	{
		if(get_vector(str[2], &(elem->vec)))
			return (EXIT_FAILURE);
		if (get_color(str[3], &(elem->color)) == ERR_INT)
			return (EXIT_FAILURE);
		elem->height = 0;
		elem->radio = 0;
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_cylinder(char **str, t_element *elem)
{
	if(!str || !elem)
		return (EXIT_FAILURE);
	if (len_mat(str) == 6)
	{
		if(get_vector(str[2], &(elem->vec)))
			return (EXIT_FAILURE);
		elem->radio = ft_atoif(str[3]) / (float)2.0;
		elem->height = ft_atoif(str[4]);
		if (get_color(str[5], &(elem->color)) == ERR_INT)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
