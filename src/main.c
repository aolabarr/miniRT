/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/22 11:16:05 by aolabarr         ###   ########.fr       */
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
		return (handle_error(ERR_EXT), EXIT_FAILURE);

	
	

	
	
	init_scene(&scene);
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
	close(fd);


	init_mlx(&scene);
	scene.mlx = mlx_init();
	if (!scene.mlx)
		return (ERR_MALL);
	if (!new_window(&scene, scene.name))
		return (ERR_MALL);
	mlx_loop_hook(scene.mlx, render_image, &scene);
	mlx_hook(scene.win, DestroyNotify, NoEventMask, handle_close, &scene);
	mlx_hook(scene.win, KeyPress, KeyPressMask, handle_key_input, &scene);
	//mlx_hook(scene->win, ButtonPress, ButtonPressMask, handle_scroll, scene);
	//mlx_hook(scene->win, MotionNotify, PointerMotionMask, mouse_move, scene);
	mlx_loop(scene.mlx);
	
	free_scene(&scene); // dentro de handle_free
	return(EXIT_SUCCESS);	
}



