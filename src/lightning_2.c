/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:48:25 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/09 15:56:06 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	get_specular_factor(float reflect_dot_eye, t_data *scene, t_comps comps)
{
	if (reflect_dot_eye < -EPSILON || ft_abs(reflect_dot_eye) < EPSILON)
		return (0);
	else
		return (calculate_specular(scene, comps, reflect_dot_eye));
}

float	get_diffuse_factor(t_data *scene, t_comps comps, float light_dot_normal)
{
	float	diffuse;

	diffuse = comps.elem.material.diffuse;
	if (scene->lig.bright == 0)
		return (scene->amb.ratio * diffuse * light_dot_normal);
	else
		return (scene->lig.bright * diffuse * light_dot_normal);
}

float	get_ambient_factor(t_data *scene, t_comps comps)
{
	if (scene->lig.bright == 0)
		return (scene->amb.ratio * comps.elem.material.ambient);
	else
		return (scene->lig.bright * comps.elem.material.ambient);
}
