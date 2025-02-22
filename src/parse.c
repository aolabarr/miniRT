/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:52:38 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 16:26:39 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	parse(t_data *scene, char *map)
{
	int 		fd;
	char		*line;
	t_element	elem;

	init_scene(scene);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return(handle_error(ERR_FD), EXIT_FAILURE);
	while((line = get_next_line(fd)))
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue;
		}
		if (line[0] == 'A')
		{
			if(get_ambient(line, &scene->amb))
				return (handle_error(ERR_SCENE),EXIT_FAILURE);
		}
		else if (line[0] == 'C')
		{
			if(get_camera(line, &scene->cam))
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
		}
		else if (line[0] == 'L')
		{
			if(get_light(line, &scene->lig))
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
		}
		else
		{
			if(get_element(line, &elem))
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
			if(add_element(scene, &elem))
				return (EXIT_FAILURE);
		}
		free (line);
	}
	close(fd);
	return(EXIT_SUCCESS);
}

