/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/08 14:01:30 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// void	decimal_to_hex(int dec)
// {
// 	char *hex_digits;

// 	*hex_digits = "0123456789ABCDEF"
	
// }

void	get_ambient(char *line, t_ambient *amb)
{
	int	i;
	
	i = 1;
	while (line)
	{
		amb->ratio = ft_atof(line + i);
			printf("RATIO %f\n", amb->ratio);
		break;
		//i++;
	}

}

float	ft_atof(char *str)
{
	int 	sign;
	int		i;
	float	result;
	float	factor;

	i = 0;
	sign = 1;
	result = 0.0;
	factor = 1.0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(ft_isdigit(str[i]))
	{
		printf("el char es: %c\n", str[i]);
		result = result * 10.0 + (str[i] - '0');
		printf("el nb es: %f\n", result);
		i++;
	}
	if(str[i] == '.')
	{
		i++;
		while(ft_isdigit(str[i]))
		{
			printf("el char es: %c\n", str[i]);
			factor *= 0.1;
			result = result + (str[i] - '0') * factor;
			printf("el nb es: %f\n", result);
			i++;
		}
	}
	result = result * sign;
	printf("el result final es: %f\n", result);
	return (result);
}

