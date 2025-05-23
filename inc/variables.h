/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:30:53 by beiglesi          #+#    #+#             */
/*   Updated: 2025/05/10 12:05:29 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdbool.h>

typedef struct s_color
{
	float		red;
	float		green;
	float		blue;
}			t_color;

typedef struct s_ambient
{
	float	ratio;
	t_color	color;
}			t_ambient;

typedef struct s_shear
{
	float	xy;
	float	xz;
	float	yx;
	float	yz;
	float	zx;
	float	zy;
}				t_shear;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		w;
}	t_coord;

typedef t_coord	t_vec;

typedef t_coord	t_pos;

typedef struct s_ang
{
	float		x;
	float		y;
	float		z;
}			t_ang;

typedef struct s_camera
{
	t_pos	pos;
	t_vec	vec;
	int		fov;
	float	theta;

}			t_camera;

typedef struct s_light
{
	t_pos		pos;
	float		bright;
	t_color		color;
}				t_light;

typedef enum e_eltype
{
	SP,
	CY,
	PL,
	UNKOWN
}			t_eltype;

typedef struct s_material
{
	t_color	color;
	float	ambient;		// valores entre 0 y 1
	float	diffuse;		// valores entre 0 y 1
	float	specular;		// valores entre 0 y 1
	float	shini;			// valores entre 10 y 200
}			t_material;

typedef struct s_element
{
	t_eltype	type;
	t_pos		pos;
	t_coord		vec;
	t_color		color;
	t_material	material;
	float		radio;
	float		height;
	float		*tr_mat;
	float		*tri_mat;
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

typedef struct s_ray
{
	t_coord	origin;
	t_vec	vec;
}			t_ray;

typedef struct s_hit
{
	bool		hit;
	float		t1;
	float		t2;
	t_element	elem;
}				t_hit;

typedef struct s_data
{
	t_ambient	amb;
	t_camera	cam;
	t_light		lig;
	t_element	*elem;
	t_vec		world_y;
	t_vec		world_z;
	float		aspect_ratio;
	float		height;
	void		*mlx;
	void		*win;
	char		*name;
	t_image		img;
	int			close;
	int			update;
	t_mouse		mouse;
	int			n_elem;
	int			has_amb;
	int			has_cam;
	int			has_lig;
}				t_data;

typedef struct s_comps
{
	float		t;
	t_element	elem;
	t_pos		point;
	t_vec		eyev;
	t_vec		normal;
	bool		inside;
	t_pos		over_point;
}				t_comps;

#endif
