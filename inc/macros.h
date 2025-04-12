/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:18:32 by beiglesi          #+#    #+#             */
/*   Updated: 2025/04/12 14:36:08 by aolabarr         ###   ########.fr       */
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

//Canvas values
# define WIDTH				800
# define ASPECT_RATIO       (16.0 / 9.0)
# define HEIGHT				(WIDTH / ASPECT_RATIO)
# define CANVAS_DISTANCE    1

// Pong model values
# define EPSILON 		    0.01
# define DIFFUSE            0.7
# define SPECULAR           0.7
# define SHININESS          200

# define NO_HIT             -1
# define SHADOW             1 
# define NO_SHADOW          0 
# define ZOOM_FACTOR 		0.1
# define MOVE_FACTOR 		0.1            

// Coordate systems and relative moves
# define WORLD_X            (t_vec){1, 0, 0, 0}
# define WORLD_Y            (t_vec){0, 1, 0, 0}
# define WORLD_Z            (t_vec){0, 0, 1, 0}
# define DELTA_TRANS        0.1

//Color palette
# define BLACK              (t_color){0, 0, 0}
# define BLUE               (t_color){0, 0, 255}
//# define SKY_BLUE           (t_color){255, 255, 255}
# define SKY_BLUE           (t_color){135, 206, 235}

//Constant macros
# define PLUS_KEY		65453
# define MINUS_KEY		65451
# define PI				3.14159265358979323846


#endif

