/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:33 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/01 17:00:46 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_extension(char *str)
{
	int	len;

	len = strlen(str) - 3;
	if (strlen <  4)
		return (EXIT_FAILURE);
	if (strncmp(str + len, ".rt", 3))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc != 2)
		return(handle_error(ERR_ARG), EXIT_FAILURE);
	if (check_extension(argv[1]))
		return (handle_error(ERR_EXT), EXIT_FAILURE);

	
}


