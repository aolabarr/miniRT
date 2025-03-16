/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/16 13:34:58 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// int	main(int argc, char **argv)
// {
// 	t_data	scene;
	
// 	if (argc != 2)
// 		return(handle_error(ERR_ARG), EXIT_FAILURE);
// 	if (check_extension(argv[1]))
// 		return (handle_error(ERR_EXT), EXIT_FAILURE);

// 	if (parse(&scene, argv[1]))
// 		return(handle_free(&scene), EXIT_FAILURE);
	
// 	if (raytracing(&scene))
// 		return(handle_free(&scene), EXIT_FAILURE);
	
// 	return(EXIT_SUCCESS);	
// }

/* main para checkear hit */


int	main(int argc, char **argv)
{
	t_data	scene;
	
	if (argc != 2)
		return(handle_error(ERR_ARG), EXIT_FAILURE);
	if (check_extension(argv[1]))
		return (handle_error(ERR_EXT), EXIT_FAILURE);

	if (parse(&scene, argv[1]))
		return(handle_free(&scene), EXIT_FAILURE);
	
	printf("Elementos: %d\n", scene.n_elem);
	printf("Tipo elemento: %d\n", scene.elem[0].type);
	printf("Posicion: %f %f %f\n", scene.elem[0].pos.x, scene.elem[0].pos.y, scene.elem[0].pos.z);
	printf("Cámara Posicion: %f %f %f\n", scene.cam.pos.x, scene.cam.pos.y, scene.cam.pos.z);
	printf("Cámara Vector: %f %f %f\n", scene.cam.vec.x, scene.cam.vec.y, scene.cam.vec.z);

	// t_ray ray;
	// ray.origin = scene.cam.pos;
	// ray.vec = scene.cam.vec;

	// printf("Hit: %d\n", calculate_hit(ray, scene.elem[0]).hit);
	// printf("t1: %f\n", calculate_hit(ray, scene.elem[0]).t1);
	// printf("t2: %f\n", calculate_hit(ray, scene.elem[0]).t2);
	if (raytracing(&scene))
		return(handle_free(&scene), EXIT_FAILURE);
	
	return(EXIT_SUCCESS);	
}
