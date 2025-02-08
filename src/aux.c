/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:36 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/08 13:57:32 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

int handle_error(int error)
{
	ft_printf("Error\n");
	if (error == ERR_ARG)
		ft_printf(ERR_MSG_ARG);
	if (error == ERR_EXT)
		printf(ERR_MSG_EXT);
	if (error == ERR_FD)
		printf(ERR_MSG_FD);
	return (EXIT_FAILURE);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	return (0);
}