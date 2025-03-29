/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/29 11:00:38 by beiglesi         ###   ########.fr       */
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
	
	if (create_scene(&scene))
		return(handle_free(&scene), EXIT_FAILURE);
	
	return(EXIT_SUCCESS);	
}

