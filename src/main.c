/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/17 15:52:15 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_data	scene;
	t_element elem;
	
	if (argc != 2)
		return(handle_error(ERR_ARG), EXIT_FAILURE);
	if (check_extension(argv[1]))
	{
		handle_error(ERR_EXT);
		return (EXIT_FAILURE);
	}	
	init_data(&scene);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(handle_error(ERR_FD), EXIT_FAILURE);
	while((line = get_next_line(fd)))
	{
		printf("LINE: %s\n", line);
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue;
		}
		if (line[0] == 'A')
		{
			if(get_ambient(line, &scene.amb))
				return (handle_error(ERR_SCENE),EXIT_FAILURE);
		}
		else if (line[0] == 'C')
		{
			if(get_camera(line, &scene.cam))
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
		}
		else if (line[0] == 'L')
		{
			if(get_light(line, &scene.lig))
				return (EXIT_FAILURE);
		}
		else
		{
			if(get_element(line, &elem))
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
			if(add_element(&scene, &elem))
				return (EXIT_FAILURE);
		}
		free (line);
	}
	close(fd);
	return(EXIT_SUCCESS);	
}


