/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:52:40 by binary            #+#    #+#             */
/*   Updated: 2025/05/05 21:52:45 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int line_isspace(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
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