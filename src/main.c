/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/10 15:52:09 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_data	scene;
	
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
		if (line[0] == 'A')
		{
			if(get_ambient(line, &scene.amb))
				return (EXIT_FAILURE);
			ft_printf("Ambient found\n");
		}
		else if (line[0] == 'C')
		{
			if(get_camera(line, &scene.cam))
				return (EXIT_FAILURE);
			printf("Camera found\n");
		}
		else if (line[0] == 'L')
			printf("Light found\n");
		else
			printf("The elements\n");
		free (line);
	}
	return(EXIT_SUCCESS);	
}


