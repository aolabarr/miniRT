/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:13 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/03 16:15:24 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int get_ambient(char *line, t_ambient *amb)
{
	char	**temp;
	int		status;

	status = EXIT_SUCCESS;
	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	if (temp && len_mat(temp) == 3)
	{
		amb->ratio = ft_atof(temp[1]);
		if (amb->ratio >= 0.0 || amb->ratio <= 1.0)
		{
			if ((amb->color = rgb_to_hex(temp[2]) == ERR_INT))
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
			if(!get_vector(temp[2], &(cam->vec)))
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
			lig->bright = ft_atof(temp[2]);
			if (lig->bright >= 0.0 || lig->bright <= 1.0)
			{
				if ((lig->color = rgb_to_hex(temp[3])) == ERR_INT)
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

int get_element(char *line, t_element *elem)
{
	char	**temp;

	if (valid_str(line))
		return (EXIT_FAILURE);
	temp = ft_split(line, ' ');
	elem->type = get_elem_type(temp[0]);
	if(get_position(temp[1], &(elem->pos)))
		return (EXIT_FAILURE);
	if (elem->type == SP)
	{
		if (get_sphere(temp, elem))
		{
			ft_free_mat(temp);
			return (EXIT_FAILURE);
		}
		// printf("SPHERE\n");
		// printf("Diam: %f\n", elem->diam);
		// printf("Color: %0X06\n", elem->color);
		// printf("Position x: %f\n", elem->pos.x);
		// printf("Position y: %f\n", elem->pos.y);
		// printf("Position z: %f\n", elem->pos.z);
		// printf("\n");
	}
	else if (elem->type == PL)
	{
		if (get_plane(temp, elem))
		{
			ft_free_mat(temp);
			return (EXIT_FAILURE);
		}
		// printf("PLANE\n");
		// printf("Vector x: %f\n", elem->vec.x);
		// printf("Vector y: %f\n", elem->vec.y);
		// printf("Vector z: %f\n", elem->vec.z);
		// printf("Color: %0X06\n", elem->color);
		// printf("Position x: %f\n", elem->pos.x);
		// printf("Position y: %f\n", elem->pos.y);
		// printf("Position z: %f\n", elem->pos.z);
		// printf("\n");
	}
	else if (elem->type == CY)
	{
		if (get_cylinder(temp, elem))
		{
			ft_free_mat(temp);
			return (EXIT_FAILURE);
		}
		// printf("CYLINDER\n");
		// printf("Diam: %f\n", elem->diam);
		// printf("Height: %f\n", elem->height);
		// printf("Color: %0X06\n", elem->color);
		// printf("Position x: %f\n", elem->pos.x);
		// printf("Position y: %f\n", elem->pos.y);
		// printf("Position z: %f\n", elem->pos.z);
		// printf("Vector x: %f\n", elem->vec.x);
		// printf("Vector y: %f\n", elem->vec.y);
		// printf("Vector z: %f\n", elem->vec.z);
		// printf("\n");
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
		free(scene->elem);
	scene->elem = new_array;
	scene->n_elem++;
	return (EXIT_SUCCESS);
}

int	get_color(char *str)
{
	t_color color;
	char	**temp;
	
	temp = ft_split(str, ',');
	if (len_mat(temp) != 3)
		return (ERR_SCENE);
	color.red = ft_atoi(temp[0]);
	if (color.red < 0 || color.red > 255)
		return (ERR_SCENE);
	color.green = ft_atoi(temp[1]);
	if (color.green < 0 || color.green > 255)
		return (ERR_SCENE);
	color.blue = ft_atoi(temp[2]);
	if (color.blue < 0 || color.blue > 255)
		return (ERR_SCENE);
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

	if (!str)
		return (ERR_SCENE);
	rgb = ft_split(str, ',');
	if (len_mat(rgb) != 3)
		return (ERR_SCENE);
	r = ft_atoi(rgb[0]);
	if (r == ERR_INT)
		return (r);
	// printf("R dec es %d\n",  ft_atoi(rgb[0]));
	g = ft_atoi(rgb[1]);
	// printf("G dec %d\n", ft_atoi(rgb[1]));
	if (g == ERR_INT)
		return (g);
	b = ft_atoi(rgb[2]);
	// printf("B dec %d\n", ft_atoi(rgb[2]));
	if (b == ERR_INT)
		return (b);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ERR_INT);

	// Conversión correcta a hexadecimal con bit shifting
	hex_color = (r << 16) | (g << 8) | b;

	ft_free_mat(rgb);
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

