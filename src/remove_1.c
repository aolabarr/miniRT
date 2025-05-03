/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:25:19 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/02 18:25:35 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ang rotation_angles(t_vec vec)
{
    float magnitude;
    t_ang angles;
	
	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (magnitude != 1.0f)
    {
        vec.x /= magnitude;
        vec.y /= magnitude;
        vec.z /= magnitude;
    }
    angles.x = atan2(vec.y, vec.x);
    angles.y = atan2(-vec.z, sqrt(vec.x * vec.x + vec.y * vec.y));
    angles.z = atan2(vec.y, vec.z);
	return (angles);
}
