/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:24:31 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/10 15:51:38 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include "variables.h"
# include "macros.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>

# include "../lib/libio/gnl/get_next_line.h"
# include "../lib/libio/ftprintf/ft_printf.h"
# include "../lib/libft/src/libft.h"


/* aux.c */
int		handle_error(int error);
int		is_space(char c);
int	    valid_str(char *str);
void	ft_free_mat(char **mat);

/* init.c */
void	init_data(t_data *scene);
void     init_ambient(t_ambient *amb);
void	init_camera(t_camera *cam);
void	init_light(t_light *light);
int		check_extension(char *str);

/* get_data.c */
int     get_ambient(char *line, t_ambient *amb);
int get_camera(char *line, t_camera *cam);
int     rgb_to_hex(char *str);
int	    ft_atoi_hex(char *str);
int	    dec_to_hex(int dec);
float	ft_atof(char *str);

#endif