/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:52:38 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 14:08:16 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	parse(t_data *scene, char *map)
{
	int		fd;
	char	*line;

	init_scene(scene);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (handle_error(ERR_FD), EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_line(line, scene))
		{
			free (line);
			close (fd);
			return (EXIT_FAILURE);
		}
		free (line);
	}
	close(fd);
	if (all_components_scene(scene))
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_line(char *line, t_data *scene)
{
	t_element	elem;
	
	/*MEJORAR LINEA EN BLANCO!*/
	if (line[0] == '\n'|| line[0] == '\0')
		return (EXIT_SUCCESS);
	if (line[0] == 'A')
		return (get_ambient(line, &scene->amb, scene));
	else if (line[0] == 'C')
		return (get_camera(line, &scene->cam, scene));
	else if (line[0] == 'L')
		return (get_light(line, &scene->lig, scene));
	else
	{
		if (get_element(line, &elem))
			return (EXIT_FAILURE);
		if (add_element(scene, &elem))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int handle_error(int error)
{
	if (error == ERR_ARG)
		ft_putendl_fd(ERR_MSG_ARG, STDOUT_FILENO);
	if (error == ERR_EXT)
		ft_putendl_fd(ERR_MSG_EXT, STDOUT_FILENO);
	if (error == ERR_FD)
		ft_putendl_fd(ERR_MSG_FD, STDOUT_FILENO);
	if (error == ERR_SCENE)
		ft_putendl_fd(ERR_MSG_SCENE, STDOUT_FILENO);
	if (error == ERR_DARK)
		ft_putendl_fd(ERR_MSG_DARK, STDOUT_FILENO);
	if (error == ERR_MISS_ELEM)
		ft_putendl_fd(ERR_MSG_MISS_ELEM, STDOUT_FILENO);
	if (error == ERR_ELEM)
		ft_putendl_fd(ERR_MSG_ELEM, STDOUT_FILENO);

	return (EXIT_FAILURE);
}

t_eltype get_elem_type(char *str)
{
	if (ft_strncmp(str, "sp", 2) == 0)
		return (SP);
	if (ft_strncmp(str, "cy", 2) == 0)
		return (CY);
	if (ft_strncmp(str, "pl", 2) == 0)	
		return (PL);
	else
		return (handle_error(ERR_ELEM), UNKOWN);
}
