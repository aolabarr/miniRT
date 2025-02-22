/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:00:05 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/20 17:52:12 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		check_extension(char *str);

void	initial_set_data(t_data *data);
void	set_initial_zoom(t_data *data);
void	*new_window(t_data *data, char *title);
int		handle_close(t_data *data);
int		close_window(t_data *data);

int	render_image(t_data *data);
int	create_image(t_data *data);
void	put_color_pixel(t_data *data, t_image img, int x, int y);

void	ft_free_v(void *str);

int	handle_key_input(int key, t_data *data);
void	set_traslation_move(t_data *data, int key);
void	set_static_zoom(t_data *data, int key);

#endif
