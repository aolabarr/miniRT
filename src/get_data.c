/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/19 11:45:15 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int get_ambient(char *line, t_ambient *amb)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	amb->ratio = ft_atof(temp[1]);
	//printf("RATIO %f\n", amb->ratio);
	amb->color = rgb_to_hex(temp[2]);
	if (amb->color == ERR_INT)
	{
		ft_free_mat(temp);
		return (EXIT_FAILURE);
	}
	//printf("COLOR 0x%06X\n", amb->color);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_camera(char *line, t_camera *cam)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	cam->pos = get_position(temp[1]);
	// printf("POS X: %f\n", cam->pos.x);
	// printf("POS Y: %f\n", cam->pos.y);
	// printf("POS Z: %f\n", cam->pos.z);
	if(get_vector(temp[2], &(cam->vec)))
		return (EXIT_FAILURE);		
	// printf("VEC X: %f\n", cam->vec.x);	
	// printf("VEC Y: %f\n", cam->vec.y);
	// printf("VEC Z: %f\n", cam->vec.z);
	cam->fov = ft_atoi(temp[3]);
	// printf("FOV %d\n", cam->fov);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_light(char *line, t_light *lig)
{
	char	**temp;

	if (valid_str(line))
		return (handle_error(ERR_SCENE), EXIT_FAILURE);
	temp = ft_split(line, ' ');
	lig->pos = get_position(temp[1]);
	// printf("POS X: %f\n", lig->pos.x);
	// printf("POS Y: %f\n", lig->pos.y);
	// printf("POS Z: %f\n", lig->pos.z);
	lig->bright = ft_atof(temp[2]);
	// printf("BRIGHT %f\n", lig->bright);
	lig->color = rgb_to_hex(temp[3]);
	if (lig->color == ERR_INT)
	{
		ft_free_mat(temp);
		return (EXIT_FAILURE);
	}
	// printf("COLOR 0x%06X\n", lig->color);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int get_element(char *line, t_element *elem)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	elem->type = get_elem_type(temp[0]);
	elem->pos = get_position(temp[1]);
	if (elem->type == SP)
	{
			elem->diam = ft_atof(temp[2]);
			elem->color = rgb_to_hex(temp[3]);
			if (elem->color == ERR_INT)
			{
				ft_free_mat(temp);
				return (EXIT_FAILURE);
			}
			elem->height = 0;
			elem->vec = (t_vector){0,0,0};
	}
	else if (elem->type == PL)
	{
		if(get_vector(temp[2], &(elem->vec)))
			return (EXIT_FAILURE);
		elem->color = rgb_to_hex(temp[3]);
		if (elem->color == ERR_INT)
			{
				ft_free_mat(temp);
				return (EXIT_FAILURE);
			}
		elem->height = 0;
		elem->diam = 0;
	}
	else if (elem->type == CY)
	{
		if(get_vector(temp[2], &(elem->vec)))
			return (EXIT_FAILURE);
		elem->diam = ft_atof(temp[3]);
		elem->height = ft_atof(temp[4]);
		elem->color = rgb_to_hex(temp[5]);
		if (elem->color == ERR_INT)
		{
			ft_free_mat(temp);
			return (EXIT_FAILURE);
		}
	}
	ft_free_mat(temp);
	return (EXIT_SUCCESS);

}

int add_element(t_data *scene, t_element *new_elem)
{
	t_element	*new_array;
	int			i;

	i = 0;
	new_array = malloc(sizeof(t_element) * (scene->n_elem + 1));
	if (!new_array)
		return (handle_error(ERR_MALL), EXIT_FAILURE);
	while(i < scene->n_elem)
	{
		new_array[i] = scene->elem[i];
		i++;
	}
	new_array[scene->n_elem] = *new_elem;
	if (scene->elem)
		free (scene->elem); //MEJORAR
	scene->elem = new_array;
	scene->n_elem++;
	return (EXIT_SUCCESS);
}


int	rgb_to_hex(char *str)
{
	int		r;
	int		g;
	int		b;
	int		hex_color;
	char	**rgb;

	if (!str)
		return (ERR_SCENE);
	rgb = ft_split(str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (ERR_SCENE);
	r = ft_atoi_hex(rgb[0]);
	if (r == ERR_INT)
		return (r);
	printf("R dec es %d\n",  ft_atoi(rgb[0]));
	g = ft_atoi_hex(rgb[1]);
	printf("G dec %d\n", ft_atoi(rgb[1]));
	if (g == ERR_INT)
		return (g);
	b = ft_atoi_hex(rgb[2]);
	printf("B dec %d\n", ft_atoi(rgb[2]));
	if (b == ERR_INT)
		return (b);
	hex_color = (r * 10000) + (g * 100) + b;
	return (hex_color);
}

int	ft_atoi_hex(char *str)
{
	int result;

	result = ft_atoi(str);
	if (result < 0 || result > 255)
		return (ERR_INT);
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

