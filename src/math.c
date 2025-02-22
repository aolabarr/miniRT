/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:21:53 by aolabarr          #+#    #+#             */
/*   Updated: 2025/02/22 18:09:20 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_position  new_lineal_point(t_position origin, t_vector vector, float t)
{
    t_position res;

    res.x = origin.x + t * vector.x;
    res.y = origin.y + t * vector.y;
    res.z = origin.z + t * vector.z;
    return(res);
}
t_vector cross_product(t_vector v1, t_vector v2)
{
    t_vector res;

    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
    return (res);
}
t_vector scalar_vec_product(t_vector vec, float scalar)
{
    t_vector res;

    res.x = vec.x * scalar;
    res.y = vec.y * scalar;
    res.z = vec.z * scalar;
    return (res);
}

