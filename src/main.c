/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/22 10:48:12 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str) - 3;
	if (ft_strlen(str) <  4)
		return (EXIT_FAILURE);
	if (ft_strncmp(str + len, ".rt", 3))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_data	scene;
	t_element elem;
	
	if (argc != 2)
		return(handle_error(ERR_ARG), EXIT_FAILURE);
	if (check_extension(argv[1]))
		return (handle_error(ERR_EXT), EXIT_FAILURE);
	*/

	initial_set_data(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ERR_MALLOC);
	if (!new_window(&data, data.name))
		return (ERR_MALLOC);
	mlx_loop_hook(data.mlx, render_image, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, handle_close, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handle_key_input, &data);
	//mlx_hook(data->win, ButtonPress, ButtonPressMask, handle_scroll, data);
	//mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
	mlx_loop(data.mlx);
	return (0);
	
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
		//printf("LINE: %s\n", line);
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
				return (handle_error(ERR_SCENE), EXIT_FAILURE);
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
	free_scene(&scene);
	close(fd);
	return(EXIT_SUCCESS);	
}


