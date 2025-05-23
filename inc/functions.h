/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:00:05 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/10 15:32:35 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* libx.c */
int			init_mlx(t_data *scene);
void		*new_window(t_data *scene, char *title);
int			handle_close(t_data *scene);
int			close_window(t_data *scene);

/* render_1.c */
int			create_scene(t_data *scene);
int			render_image(t_data *scene);
int			create_image(t_data *scene);

/* render_2.c */
void		put_color_pixel(t_data *scene, t_image img, int x, int y);
void		compute_lighting(t_data *scene, t_color *amb_all, t_color *lig_all);
t_color		compute_color_for_pixel(t_data *scene, t_ray ray,
				t_color amb, t_color lig);
t_color		background_color(float r, float g, float b);

/* keys.c */
int			handle_key_input(int key, t_data *scene);
void		set_traslation_move(t_data *scene, int key);
void		set_static_zoom(t_data *scene, int key);
void		set_rotation_move(t_data *scene, int key);
void		set_orientation(t_data *scene, int key, t_pos to, t_vec *rigth_up);

/* aux.c */
int			get_position(char *str, t_pos *pos);
int			get_vector(char *str, t_vec *vec);
char		**ft_split_allwhitespace(const char *s);
size_t		ft_word_count_allwhitespace(const char *s);
size_t		ft_char_count_allwhitespace(const char *s);

/*utils.c*/
int			is_space(char c);
int			valid_str(char *str);
int			is_element(char *str);
void		*ft_memsetf(void *b, float c, int len);
void		*ft_callocf(int count, int size);

/* init_1.c */
void		init_scene(t_data *scene);
void		init_ambient(t_ambient *amb);
void		init_camera(t_camera *cam);
void		init_light(t_light *light);
void		init_color(t_color *color);

/* init_2.c */
void		init_canvas(t_data *scene);
void		put_canvas_values(t_data *scene, t_vec *right_up, t_pos center);

/* get_data_1.c */
int			get_ambient(char *line, t_ambient *amb, t_data *scene);
int			get_camera(char *line, t_camera *cam, t_data *scene);
int			get_light(char *line, t_light *lig, t_data *scene);
int			get_element(char *line, t_element *elem);

/* get_data_2.c */
int			add_element(t_data *scene, t_element *new_elem);
int			get_color(char *str, t_color *color);
int			rgb_to_hex(t_color color);
float		clamp_color(float color);

/* check_values_1.c */
int			normalized_vector(t_vec vec);
int			len_mat(char **str);
int			get_sphere(char **str, t_element *elem);
int			get_plane(char **str, t_element *elem);
int			get_cylinder(char **str, t_element *elem);

/* check_values_2.c */
int			all_components_scene(t_data *scene);
int			check_extension(char *str);
int			vector_isequal(t_vec v1, t_vec v2);

/* free.c */
void		ft_free_mat(char **mat);
char		**ft_free_mat_n(char **mat, size_t mlen);
void		free_scene(t_data *scene);
void		ft_free_v(void *str);
void		free_scene_first(t_data *scene);

/* parse.c */
int			parse(t_data *scene, char *map);
int			parse_line(char *line, t_data *scene);
int			handle_error(int error);
t_eltype	get_elem_type(char *str);

/* raytracing 1.c */
t_pos		calc_pixel_position(int x, int y, t_pos *canvas, float height);
void		ray_transform_to_local(t_element *elem, t_ray ray,
				t_ray *ray_local);
t_pos		get_hit_point(t_ray ray, t_hit hit);
float		hit_t(t_hit hit);

/* raytracing 2.c */
t_vec		normal_at(t_element elem, t_pos hit_wd_point);
t_vec		reflect_at(t_vec in, t_vec normal);
t_color		add_color_intensity(t_color color, float intensity);
t_color		create_color(float r, float g, float b);
void		init_pong_parameters(t_data *scene);

/* raytracing 3.c */
t_hit		*intersect_world(t_ray ray, t_data *scene);
t_comps		prepare_computations(t_hit hit, t_ray ray);
void		calc_inside(t_comps *comps);
float		get_object_scale(t_element elem);
float		shade_hit(t_data *scene, t_comps comps);
int			line_isspace(char *str);

/* raytracing 4.c */
t_ray		create_ray(t_data *scene, t_image img, int x, int y);
t_hit		find_hit(t_data *scene, t_hit *inters);
void		update_hit(t_hit *hit, t_hit inter);

/* ligthning.c */
float		lightning(t_data *scene, t_comps comps, int in_shadow);
void		diffuse_specular_zero(float *colors);
float		calculate_specular(t_data *scene, t_comps comps,
				float reflect_dot_eye);
int			is_shadowed(t_data *scene, t_pos point);
float		get_specular_factor(float reflect_dot_eye, t_data *scene,
				t_comps comps);
float		get_diffuse_factor(t_data *scene, t_comps comps,
				float light_dot_normal);
float		get_ambient_factor(t_data *scene, t_comps comps);

/* color.c*/
t_color		hadamard_product(t_color col1, t_color col2);
t_color		mult_color_scalar(t_color col, float scalar);
t_color		add_colors(t_color col1, t_color col2);

/* math_1.c */
int			is_coord_equal(t_coord a, t_coord b);
t_vec		sum_vector(t_vec a, t_vec b);
t_vec		rest_coord(t_coord a, t_coord b);
t_vec		opp_vector(t_vec vec);

/* math_2.c */
float		magnitude(t_vec vec);
t_vec		normalize(t_vec vec);
float		dot_product(t_vec a, t_vec b);
t_pos		sum_coord(t_pos coord1, t_pos coord2);
t_pos		mult_coord_float(t_pos coord1, float t);

/* math_3.c */
float		ft_pow(float num, int pow);
int			is_zerovector(t_vec vec);
float		ft_abs(float num);
int			is_equal(float a, float b);
int			is_zero(float num);

/* math_4.c */
t_vec		scalar_product(t_vec vec, float scalar);
t_vec		cross_product(t_vec v1, t_vec v2);
t_pos		new_lineal_point(t_pos origin, t_vec vector, float t);
t_pos		zero_pos(void);

/* intersection.c */
t_pos		position(t_ray ray, float t);
t_hit		sphere_intersection(t_ray ray, t_element elem);
t_hit		plane_intersection(t_ray ray, t_element elem);
t_hit		cylinder_intersection(t_ray ray, t_element elem);
bool		truncate_cylinder(t_ray ray, t_element elem, float t1, float t2);

/* matrix_0.c*/
int			invert_matrix(float *mat, float *inv);
void		minor_matrix(float *mat, float *minor, int row, int col);
float		cofactor(float *mat, int row, int col);
void		cofactor_matrix(float *mat, float *res);
void		calculate_minor_row(int col, float *minor, float *mat, int *aux);

/* matrix_1.c*/

void		multiply_matrix(float *mat1, float *mat2, float *res);
void		multiply_matrix_vector(float *mat, t_vec vector, t_vec *res);
void		init_coordf(float *coord);
void		copy_coord_to_array(t_coord coord, float *array);
void		multiply_matrix_pos(float *mat, t_pos point, t_pos *res);

/* matrix_2.c*/
void		rotation_x_matrix(float angle, float *mat);
void		rotation_y_matrix(float angle, float *mat);
void		rotation_z_matrix(float angle, float *mat);
void		rotation_matrix(t_ang angles, float *mat);
void		rotation_inv_matrix(t_ang angles, float *mat);

/* matrix_3.c*/
float		determinant_matrix(float *mat);
void		shearing_matrix(t_shear shear, float *mat);
void		translation_matrix(t_pos point, float *mat);
void		scale_matrix(float x, float y, float z, float *mat);

/* matrix_4.c*/
int			is_equal_matrix(float *mat1, float *mat2);
void		identity_matrix(float *mat);
void		transpose_matrix(float *mat, float *res);

/* trans_1.c*/
int			init_trans_matrix(t_data *scene);
int			get_trans_matrix(t_element *elem, t_data *scene);
int			get_trans_inv_matrix(t_element *elem, t_data *scene);

/* trans_2.c*/
float		*init_zero(float *mat_s, float *mat_t, float *mat_r, float *aux);
void		handle_scale(t_element *elem, float *mat_s, int dir);
void		handle_rotation(t_element *elem, float *mat_r, int dir, t_data *sc);
void		rodrigues_matrix(t_vec a, float angle, float *mat);
void		rotation_matrix_from_to(t_vec from, t_vec to, float *mat);

/* trans_view.c*/
void		view_transform(t_pos from, t_pos to, t_vec up, float *mat);
void		transform_cam(t_pos from, t_pos to, t_vec up, t_data *scene);

#endif
