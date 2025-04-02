/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:30:53 by beiglesi          #+#    #+#             */
/*   Updated: 2025/04/02 13:21:58 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdbool.h>

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
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
}			t_shear;

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
	t_vec		vec;
	int			fov;

}			t_camera;


typedef struct s_light
{
	t_coord		pos;
	float		bright;
	t_color		color;
}				t_light;

typedef	enum e_eltype
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
	t_coord		pos;
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
	void		*mlx;
	void		*win;
	char		*name;
	t_image		img;
	int			close;
	int			update;
	t_mouse		mouse;
	int			n_elem;
}				t_data;

typedef struct s_comps
{
	float		t;
	t_element 	elem;
	t_pos		point;
	t_vec		eyev;
	t_vec		normal;
	bool		inside;
}				t_comps;



#endif
