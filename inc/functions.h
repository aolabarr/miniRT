/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:00:05 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/12 07:53:59 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* libx.c */
void	init_mlx(t_data *scene);
void	init_canvas(t_data *scene);
void	*new_window(t_data *scene, char *title);
int		handle_close(t_data *scene);
int		close_window(t_data *scene);

/* render.c */
int	    render_image(t_data *scene);
int	    create_image(t_data *scene);
void	put_color_pixel(t_data *scene, t_image img, int x, int y);

/* keys.c */
int     handle_key_input(int key, t_data *scene);
void	set_traslation_move(t_data *scene, int key);
void	set_static_zoom(t_data *scene, int key);

/* aux.c */
int		    handle_error(int error);
int		    is_space(char c);
int	        valid_str(char *str);
int			get_position(char *str, t_coord  *pos);
int         get_vector(char *str, t_coord  *vec);
t_eltype	get_elem_type(char *str);
int         is_element(char *str);

/* init.c */
void	init_scene(t_data *scene);
void    init_ambient(t_ambient *amb);
void	init_camera(t_camera *cam);
void	init_light(t_light *light);
void	init_color(t_color *color);
int		check_extension(char *str);

/* get_data.c */
int     get_ambient(char *line, t_ambient *amb);
int     get_camera(char *line, t_camera *cam);
int     get_light(char *line, t_light *lig);
int		get_element(char *line, t_element *elem);
int		add_element(t_data *scene, t_element *new_elem);
int     get_color(char *str, t_color *color);
int     rgb_to_hex(t_color color);
int     clamp_color(int color);
int	    ft_atoi_hex(char *str);
int	    dec_to_hex(int dec);
float	ft_atof(char *str);

/* check_values.c */
int     normalized_vector(t_coord vec);
int     len_mat(char **str);
int		get_sphere (char **str, t_element *elem);
int		get_plane(char **str, t_element *elem);
int		get_cylinder(char **str, t_element *elem);

/* free.c */
void    handle_free(t_data *scene);
void    ft_free_mat(char **mat);
void	free_scene(t_data *scene);
void	ft_free_v(void *str);

/* parse.c */
int	parse(t_data *scene, char *map);

/* raytracing.c */
int raytracing(t_data *scene);

/* colors_test.c*/
void testing_colors(t_data *scene);
t_color blend_colors(t_color col1, t_color col2, float ratio);

/* math_1.c */
float myabs(float num);
int is_equal(float a, float b);
int is_coord_equal(t_coord a, t_coord b);
t_vec sum_vector(t_vec a, t_vec b);
t_vec rest_coord(t_coord a, t_coord b);
t_vec opp_vector(t_vec vec);
t_vec scalar_product(t_vec vec, float scalar);
t_vec cross_product(t_vec v1, t_vec v2);

/* math_2.c */
float magnitude(t_vec vec);
t_vec normalize(t_vec vec);
float dot_product(t_vec a, t_vec b);

/* intersection.c */
t_pos	position(t_ray ray, float t);
t_pos	new_lineal_point(t_pos point, t_vec vec);
t_hit	calculate_hit(t_ray ray, t_element elem);


// /* math_1.c */
// /* math.c */
// t_position  new_lineal_point(t_position origin, t_vector vector, float t);
// t_vector cross_product(t_vector v1, t_vector v2);
// t_vector scalar_vec_product(t_vector vec, float scalar);

#endif
