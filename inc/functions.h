/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:00:05 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/01 11:38:09 by beiglesi         ###   ########.fr       */
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
int		check_extension(char *str);

/* get_data.c */
int     get_ambient(char *line, t_ambient *amb);
int     get_camera(char *line, t_camera *cam);
int     get_light(char *line, t_light *lig);
int		get_element(char *line, t_element *elem);
int		add_element(t_data *scene, t_element *new_elem);
int     rgb_to_hex(char *str);
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

// /* math.c */
// t_position  new_lineal_point(t_position origin, t_vector vector, float t);
// t_vector cross_product(t_vector v1, t_vector v2);
// t_vector scalar_vec_product(t_vector vec, float scalar);

#endif
