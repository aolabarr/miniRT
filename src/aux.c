/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:36 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/12 13:07:59 by binary           ###   ########.fr       */
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
	if (error == ERR_SCENE)
		printf(ERR_MSG_SCENE);
	return (EXIT_FAILURE);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	return (0);
}

int	valid_str(char *str)
{
	int i;

	i = 1;
	if (!str)
		return(1);
	while(str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' \
			|| str[i] == '-' || is_space(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_free_mat(char **mat)
{
	int i;

	i = 0;
	if (!mat)
		return ;
	while(mat[i])
	{
		if (mat[i])
			free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
	return ;
}

t_position	get_position(char *str)
{
	t_position pos;
	char **temp;

	temp = ft_split(str, ',');
	pos.x = ft_atof(temp[0]);
	pos.y = ft_atof(temp[1]);
	pos.z = ft_atof(temp[2]);
	ft_free_mat(temp);
	return (pos);
}

t_vector	get_vector(char *str)
{
	t_vector	vec;
	char		**temp;

	temp = ft_split(str, ',');
	vec.x = ft_atof(temp[0]);
	vec.y = ft_atof(temp[1]);
	vec.z = ft_atof(temp[2]);
	ft_free_mat(temp);
	return (vec);
}