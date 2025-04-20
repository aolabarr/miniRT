/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:36 by beiglesi          #+#    #+#             */
/*   Updated: 2025/04/20 23:14:08 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

int handle_error(int error)
{
	//ft_printf("Error\n");
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
	if (error == ERR_AMB)
		ft_putendl_fd(ERR_MSG_AMB, STDOUT_FILENO);
	if (error == ERR_CAM)
		ft_putendl_fd(ERR_MSG_CAM, STDOUT_FILENO);
	if (error == ERR_LIG)
		ft_putendl_fd(ERR_MSG_LIG, STDOUT_FILENO);
	if (error == ERR_ELEM)
		ft_putendl_fd(ERR_MSG_ELEM, STDOUT_FILENO);

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
	if(is_element(str))
	{
		i = 2;
	}
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

int	get_position(char *str, t_coord *pos)
{
	char **temp;

	temp = ft_split(str, ',');
	if (len_mat(temp) != 3)
	{
		ft_free_mat(temp);
		return (ERR_SCENE);
	}
	pos->x = ft_atoif(temp[0]);
	pos->y = ft_atoif(temp[1]);
	pos->z = ft_atoif(temp[2]);
	pos->w = POINT;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_vector(char *str, t_coord *vec)
{
	char		**temp;

	temp = ft_split(str, ',');
	vec->x = ft_atoif(temp[0]);
	vec->y = ft_atoif(temp[1]);
	vec->z = ft_atoif(temp[2]);
	vec->w = VECTOR;
	ft_free_mat(temp);
	*vec = normalize(*vec);
	return (EXIT_SUCCESS);
}

t_eltype get_elem_type(char *str)
{
	if (ft_strncmp(str, "sp", 2) == 0)
		return (SP);
	if (ft_strncmp(str, "cy", 2) == 0)
		return (CY);
	if (ft_strncmp(str, "pl", 2) == 0)	
		return (PL);
	else
		return (handle_error(ERR_ELEM), UNKOWN);
}

int is_element(char *str)
{
	if (!ft_strncmp(str, "sp", 2) || !ft_strncmp(str, "cy", 2) || !ft_strncmp(str, "pl", 2))
		return (1);
	else
		return (0);
}
void	*ft_memsetf(void *b, float c, int len)
{
	float	*str;
	int	i;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
void	*ft_callocf(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memsetf(ptr, 0.0, size);
	return (ptr);
}
