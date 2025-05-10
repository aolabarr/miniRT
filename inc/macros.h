/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:08:17 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/10 15:48:08 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// Flags
# define POINT				1
# define VECTOR				0
# define TRUE				1
# define FALSE				0
# define SHADOW             1
# define NO_SHADOW          0
# define NORMAL             0
# define INVERSE            1
# define NO_HIT             2147483647

# define ERR_ARG			0
# define ERR_EXT			1
# define ERR_FD				2
# define ERR_ELEM			4 
# define ERR_MALL			5 
# define ERR_INT			-1
# define ERR_MISS_ELEM		-2
# define ERR_SCENE			-3
# define ERR_DARK			-4
# define ERR_DUPL_ELEM		-5

# define ERR_MSG_ARG		"Error: incorrect number of arguments"
# define ERR_MSG_EXT 		"Error: incorrect file extension"
# define ERR_MSG_MALL       "SYS ERROR: malloc failed"
# define ERR_MSG_FD         "Error: can not open file"
# define ERR_MSG_SCENE      "Error: invalid data in scene"
# define ERR_MSG_ELEM       "Error: invalid element"
# define ERR_MSG_DARK		"Error: scene is in the dark"
# define ERR_MSG_MISS_ELEM	"Error: scene missing element"
# define ERR_MSG_DUPL_ELEM	"Error: scene duplicate elements"

# define ESC_MSG 			"ESC key pressed"
# define MINI_RT    		"miniRT"

//Canvas values
# define WIDTH				900
# define ASPECT_1           16.0
# define ASPECT_2           9.0
# define CANVAS_DISTANCE    1

// Pong model values
# define EPSILON 		    0.001
# define DIFFUSE            0.7
# define SPECULAR           0.7
# define SHININESS          200

// Moves
# define ZOOM_FACTOR 		0.3
# define MOVE_FACTOR 		0.3
# define DELTA_TR        	0.3
# define DELTA_ROT          0.3
# define TOL_ANGLE          2         

//Color
# define BACKGROUND_R       0.5
# define BACKGROUND_B       0.8
# define BACKGROUND_G       0.92
# define MIN_RGB			0
# define MAX_RGB			255

//Keys
# define PLUS_KEY		65453
# define MINUS_KEY		65451
# define A_KEY		    97
# define D_KEY		    100
# define W_KEY		    119
# define S_KEY		    115

//Constants
# define PI				3.14159265358979323846

#endif
