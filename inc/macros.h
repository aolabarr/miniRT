/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:32 by beiglesi          #+#    #+#             */
/*   Updated: 2025/03/26 11:05:43 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define POINT 1
# define VECTOR 0

# define ERR_ARG   	0
# define ERR_EXT   	1
# define ERR_FD		2
# define ERR_ELEM	4 
# define ERR_MALL	5 
# define ERR_INT    -1
# define ERR_SCENE  -3

# define ERR_MSG_ARG		"Error: incorrect number of arguments"
# define ERR_MSG_EXT 		"Error: incorrect file extension"
# define ERR_MSG_MALL       "SYS ERROR: malloc failed"
# define ERR_MSG_FD         "Error: can not open file"
# define ERR_MSG_SCENE      "Error: invalid data in scene"
# define ERR_MSG_ELEM       "Error: invalid element"


# define ESC_MSG 			"ESC key pressed"
# define MINI_RT    		"miniRT"

//Variable macros
# define WIDTH				800
# define ASPECT_RATIO       (16.0 / 9.0)
# define HEIGHT				(WIDTH / ASPECT_RATIO)
# define CANVAS_DISTANCE    1

# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05
# define EPSILON 		    0.0001
# define NO_HIT             -1


//Constant macros
# define DOM_MIN		-2.0
# define DOM_MAX		2.0
# define PLUS_KEY		65453
# define MINUS_KEY		65451
# define PI				3.14159265358979323846
# define TOL			0.00001

//Color palette
#define GREEN       0x00FF00 // Verde
#define YELLOW      0xFFFF00 // Amarillo
#define ORANGE      0xFFA500 // Naranja
#define PINK        0xFFC0CB // Rosa
#define TEAL        0x008080 // Verde azulado
#define BLACK       0x000000 // Negro

#endif

