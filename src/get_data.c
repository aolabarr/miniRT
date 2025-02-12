/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/12 13:09:49 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int get_ambient(char *line, t_ambient *amb)
{
	char	**mat;

	if (valid_str(line))
		return (handle_error(ERR_SCENE), EXIT_FAILURE);
	mat = ft_split(line, ' ');
	amb->ratio = ft_atof(mat[1]);
	//printf("RATIO %f\n", amb->ratio);
	amb->color = rgb_to_hex(mat[2]);
	//printf("COLOR 0x%06X\n", amb->color);
	ft_free_mat(mat);
	return (EXIT_SUCCESS);
}

int get_camera(char *line, t_camera *cam)
{
	char	**temp;

	if (valid_str(line))
		return (handle_error(ERR_SCENE), EXIT_FAILURE);
	printf("CAMERA %s\n", line);
	temp = ft_split(line, ' ');
	cam->pos = get_position(temp[1]);
	printf("POS X: %f\n", cam->pos.x);
	printf("POS Y: %f\n", cam->pos.y);
	printf("POS Z: %f\n", cam->pos.z);
	cam->vec = get_vector(temp[2]);
	printf("VEC X: %f\n", cam->vec.x);	
	printf("VEC Y: %f\n", cam->vec.y);
	printf("VEC Z: %f\n", cam->vec.z);
	cam->fov = ft_atoi(temp[3]);
	printf("FOV %d\n", cam->fov);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}


int	rgb_to_hex(char *str)
{
	int		r;
	int		g;
	int		b;
	int		hex_color;
	char	**rgb;

	rgb = ft_split(str, ',');
	r = ft_atoi_hex(rgb[0]);
	//printf("R dec es %d\n",  ft_atoi(rgb[0]));
	g = ft_atoi_hex(rgb[1]);
	//printf("G dec %d\n", ft_atoi(rgb[1]));
	b = ft_atoi_hex(rgb[2]);
	//printf("B dec %d\n", ft_atoi(rgb[2]));
	hex_color = (r * 10000) + (g * 100) + b;
	return (hex_color);
}

int	ft_atoi_hex(char *str)
{
	int result;

	result = ft_atoi(str);
	result = dec_to_hex(result);
	return (result);
}

int	dec_to_hex(int dec)
{	
	int		hex;
	int 	factor;
	int		remainder;
	
	hex = 0;
	factor = 1;
	remainder = 0;
	while (dec > 0)
	{
		remainder = dec % 16;
		hex += remainder * factor;
		factor *= 10;
		dec = dec / 16;
	}
	return (hex);
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
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if(str[i] == '.')
	{
		i++;
		while(ft_isdigit(str[i]))
		{
			factor *= 0.1;
			result = result + (str[i] - '0') * factor;
			i++;
		}
	}
	result = result * sign;
	return (result);
}

