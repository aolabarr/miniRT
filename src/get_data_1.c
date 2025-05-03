/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/05/03 10:24:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	get_ambient(char *line, t_ambient *amb, t_data *scene)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split_allwhitespace(line);
	if (!temp || len_mat(temp) != 3)
		return (ft_free_mat(temp), EXIT_FAILURE);
	amb->ratio = ft_atoif(temp[1]);
	if (amb->ratio < 0.0 || amb->ratio > 1.0)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_color(temp[2], &(amb->color)) == ERR_INT)
		return (ft_free_mat(temp), EXIT_FAILURE);
	scene->has_amb = TRUE;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_camera(char *line, t_camera *cam, t_data *scene)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split_allwhitespace(line);
	if (!temp || len_mat(temp) != 4)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_position(temp[1], &(cam->pos)) != EXIT_SUCCESS)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_vector(temp[2], &(cam->vec)) != EXIT_SUCCESS)
		return (ft_free_mat(temp), EXIT_FAILURE);
	cam->fov = ft_atoi(temp[3]);
	cam->theta = ft_abs(acos(cam->vec.y));
	scene->has_cam = TRUE;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_light(char *line, t_light *lig, t_data *scene)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split_allwhitespace(line);
	if (!temp || len_mat(temp) != 4)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_position(temp[1], &(lig->pos)) != EXIT_SUCCESS)
		return (ft_free_mat(temp), EXIT_FAILURE);
	lig->bright = ft_atoif(temp[2]);
	if (lig->bright < 0.0 || lig->bright > 1.0)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_color(temp[3], &lig->color) == ERR_INT)
		return (ft_free_mat(temp), EXIT_FAILURE);
	scene->has_lig = TRUE;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_element(char *line, t_element *elem)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split_allwhitespace(line);
	elem->type = get_elem_type(temp[0]);
	if (elem->type == UNKOWN)
		return (ft_free_mat(temp), EXIT_FAILURE);
	if (get_position(temp[1], &(elem->pos)))
		return (EXIT_FAILURE);
	if (elem->type == SP && get_sphere(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	else if (elem->type == PL && get_plane(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	else if (elem->type == CY && get_cylinder(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}
