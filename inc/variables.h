/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:30:53 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/01 11:30:30 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

typedef struct s_ambient
{
	float	ratio;
	int		color;
}			t_ambient;

// typedef struct s_position
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }			t_position;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		w;
}			t_coord;

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
	PL,
	UNKOWN
}			t_eltype;

typedef struct s_element
{
	t_eltype	type;
	t_position	pos;
	t_vector	vec;
	int			color;
	float		diam;
	float		height;
}			t_element;


typedef struct s_image
{
	void		*ptr;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			update;
	t_position		canvas[4];
	float		zoom;
}				t_image;

typedef struct s_mouse
{
	float	x;
	float	y;
}			t_mouse;

typedef struct s_data
{
	t_ambient	amb;
	t_camera	cam;
	t_light		lig;
	t_element	*elem;
	void		*mlx;
	void		*win;
	char		*name;
	t_image		img;
	int			close;
	int			update;
	t_mouse		mouse;
	int			n_elem;
}				t_data;

#endif
