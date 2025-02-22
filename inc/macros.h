/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:32 by beiglesi          #+#    #+#             */
/*   Updated: 2025/02/22 10:39:49 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ERR_ARG   	0
# define ERR_EXT   	1
# define ERR_FD		2
# define ERR_SCENE  -3
# define ERR_ELEM	4 
# define ERR_MALL	5 
# define ERR_INT    -1 
# define ERR_MALLOC 2

# define ERR_MSG_ARG		"Error: incorrect number of arguments"
# define ERR_MSG_EXT 		"Error: incorrect file extension"
# define ERR_MSG_MALLOC		"SYS ERROR: malloc failed"

# define ESC_MSG 			"ESC key pressed"

# define MINI_RT    		"miniRT"

//Variable macros
# define WIDTH				800
# define HEIGHT				800
# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05

//Constant macros
# define DOM_MIN		-2.0
# define DOM_MAX		2.0
# define PLUS_KEY		65453
# define MINUS_KEY		65451
# define PI				3.14159265358979323846
# define TOL			0.00001

//Color palette - convergent points
#define GREEN       0x00FF00 // Verde
#define YELLOW      0xFFFF00 // Amarillo
#define ORANGE      0xFFA500 // Naranja
#define PINK        0xFFC0CB // Rosa
#define TEAL        0x008080 // Verde azulado
#define BLACK       0x000000 // Negro
# define ERR_MSG_FD "Error: can not open file"
# define ERR_MSG_SCENE "Error: invalid data in scene"
# define ERR_MSG_ELEM "Error: invalid element"
# define ERR_MSG_MALL "Error MALLOC"
#endif

