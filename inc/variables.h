/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:30:53 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/01 12:24:00 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

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
}			t_coord, t_pos, t_vec;

typedef struct s_camera
{
	t_coord 	pos;
	t_coord 	vec;
	int			fov;

}			t_camera;


typedef struct s_light
{
	t_coord		pos;
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
	t_coord		pos;
	t_coord		vec;
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
	t_coord		canvas[4];
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
