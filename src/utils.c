/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:47:46 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/05 21:53:40 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	return (0);
}

int	valid_str(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (1);
	if (is_element(str))
	{
		i = 2;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' \
			|| str[i] == '-' || is_space(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_element(char *str)
{
	if (!ft_strncmp(str, "sp", 2) || !ft_strncmp(str, "cy", 2) || !ft_strncmp(str, "pl", 2))
		return (1);
	else
		return (0);
}

void	*ft_memsetf(void *b, float c, int len)
{
	float	*str;
	int		i;

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
