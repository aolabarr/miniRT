/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/22 16:17:23 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	t_data	scene;
	
	if (argc != 2)
		return(handle_error(ERR_ARG), EXIT_FAILURE);
	if (check_extension(argv[1]))
		return (handle_error(ERR_EXT), EXIT_FAILURE);

	if (parse(&scene, argv[1]))
		return(handle_free(&scene), EXIT_FAILURE);
	printf("Figure: %d y color %0X\n", scene.elem[0].type, scene.elem[0].color);
	printf("Figure: %d y color %0X\n", scene.elem[1].type, scene.elem[1].color);	

	
	if (raytracing(&scene))
		return(handle_free(&scene), EXIT_FAILURE);
	
	return(EXIT_SUCCESS);	
}



