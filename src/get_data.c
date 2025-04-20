/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/04/20 12:27:14 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	get_ambient(char *line, t_ambient *amb)
{
	char	**temp;
	int		status;

	status = EXIT_SUCCESS;
	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	if (temp && len_mat(temp) == 3)
	{
		amb->ratio = ft_atoif(temp[1]);
		if (amb->ratio >= 0.0 && amb->ratio <= 1.0)
		{
			if (get_color(temp[2], &(amb->color)) == ERR_INT)
				status = EXIT_FAILURE;
		}
		else
			status = EXIT_FAILURE;
	}
	else
		status = EXIT_FAILURE;
	ft_free_mat(temp);
	return (status);
}

int	get_camera(char *line, t_camera *cam)
{
	char	**temp;
	int		status;

	status = EXIT_SUCCESS;
	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	if (temp && len_mat(temp) == 4)
	{
		if (!get_position(temp[1], &(cam->pos)))
		{
			if (!get_vector(temp[2], &(cam->vec)))
				cam->fov = ft_atoi(temp[3]);
			else
				status = EXIT_FAILURE;
		}
		else
			status = EXIT_FAILURE;
	}
	else
		status = EXIT_FAILURE;
	ft_free_mat(temp);
	return (status);
}

int	get_light(char *line, t_light *lig)
{
	char	**temp;
	int		status;

	status = EXIT_SUCCESS;
	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	if (temp && len_mat(temp) == 4)
	{
		if (!get_position(temp[1], &(lig->pos)))
		{
			lig->bright = ft_atoif(temp[2]);
			if (lig->bright >= 0.0 && lig->bright <= 1.0)
			{
				if (get_color(temp[3], &lig->color) == ERR_SCENE)
					status = EXIT_FAILURE;
			}
			else
				status = EXIT_FAILURE;
		}
		else
			status = EXIT_FAILURE;
	}
	else
		status = EXIT_FAILURE;
	ft_free_mat(temp);
	return (status);
}

int	get_element(char *line, t_element *elem)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	elem->type = get_elem_type(temp[0]);
	if (get_position(temp[1], &(elem->pos)))
		return (EXIT_FAILURE);
	if (elem->type == SP && get_sphere(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	else if (elem->type == PL && get_plane(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	else if (elem->type == CY && get_cylinder(temp, elem))
		return (ft_free_mat(temp), EXIT_FAILURE);
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	add_element(t_data *scene, t_element *new_elem)
{
	t_element	*new_array;
	int			i;

	i = 0;
	new_array = malloc(sizeof(t_element) * (scene->n_elem + 1));
	if (!new_array)
		return (handle_error(ERR_MALL), EXIT_FAILURE);
	while (i < scene->n_elem)
	{
		new_array[i] = scene->elem[i];
		i++;
	}
	new_array[scene->n_elem] = *new_elem;
	if (scene->elem)
		free(scene->elem);
	scene->elem = new_array;
	scene->n_elem++;
	return (EXIT_SUCCESS);
}

int	get_color(char *str, t_color *color)
{
	char	**temp;
	int		rgb[3];

	temp = ft_split(str, ',');
	if (!temp || len_mat(temp) != 3)
		return (ft_free_mat(temp), ERR_INT);
	rgb[0] = ft_atoi(temp[0]);
	if (rgb[0] < MIN_RGB || rgb[0] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	rgb[1] = ft_atoi(temp[1]);
	if (rgb[1] < MIN_RGB || rgb[1] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	rgb[2] = ft_atoi(temp[2]);
	if (rgb[2] < MIN_RGB || rgb[2] > MAX_RGB)
		return (ft_free_mat(temp), ERR_INT);
	color->red = rgb[0] / 255.0f;
	color->green = rgb[1] / 255.0f;
	color->blue = rgb[2] / 255.0f;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	rgb_to_hex(t_color col)
{
	int		hexcol;

	col.red = clamp_color((int)(col.red * 255));
	col.green = clamp_color((int)(col.green * 255));
	col.blue = clamp_color((int)(col.blue * 255));
	hexcol = ((int)(col.red) << 16) | ((int)(col.green) << 8) | (int)(col.blue);
	return (hexcol);
}

float	clamp_color(float color)
{
	if (color < MIN_RGB)
		return (MIN_RGB);
	if (color > MAX_RGB)
		return (MAX_RGB);
	return (color);
}

// int	ft_atoi_hex(char *str)
// {
// 	int result;

// 	result = ft_atoi(str);
// 	if (result < 0 || result > 255)
// 		return (ERR_INT);
// 	result = dec_to_hex(result);
// 	return (result);
// }

// int	dec_to_hex(int dec)
// {	
// 	int		hex;
// 	int 	factor;
// 	int		remainder;
// 	hex = 0;
// 	factor = 1;
// 	remainder = 0;
// 	while (dec > 0)
// 	{
// 		remainder = dec % 16;
// 		hex += remainder * factor;
// 		factor *= 10;
// 		dec = dec / 16;
// 	}
// 	return (hex);
// }

// float	ft_atoif(char *str)
// {
// 	int 	sign;
// 	int		i;
// 	float	result;
// 	float	factor;

// 	i = 0;
// 	sign = 1;
// 	result = 0.0;
// 	factor = 1.0;
// 	while (is_space(str[i]))
// 		i++;
// 	if (str[i] == '-')
// 		sign = -1;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while(ft_isdigit(str[i]))
// 	{
// 		result = result * 10.0 + (str[i] - '0');
// 		i++;
// 	}
// 	if(str[i] == '.')
// 	{
// 		i++;
// 		while(ft_isdigit(str[i]))
// 		{
// 			factor *= 0.1;
// 			result = result + (str[i] - '0') * factor;
// 			i++;
// 		}
// 	}
// 	result = result * sign;
// 	return (result);
// }
