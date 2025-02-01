/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:30:53 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/01 17:13:24 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct s_ambient
{
	float	ratio;
	int		color;
}			t_ambient;

typedef struct s_position
{
	float	x;
	float	y;
	float	z;
}			t_position;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}			t_vector;

typedef struct s_camera
{
	t_position	pos;
	t_vector	vec;
	int			fov;

}			t_camera;


typedef struct s_light
{
	t_position	pos;
	float		bright;
	int			color;
}				t_light;

typedef	enum e_eltype
{
	SP,
	CY,
	PL
}			t_eltype;

typedef struct s_element
{
	t_eltype	type;
	t_position	pos;
	int			color;
	float		diam;
	float		height;
	t_vector	vec;
	
}			t_element;

typedef struct s_data
{
	t_ambient	amb;
	t_camera	cam;
	t_light		lig;
	t_element	*elem;
}				t_data;

#endif