/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:38:58 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 14:15:45 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit   *intersect_world(t_ray ray, t_data *scene)
{
    int     i;
    t_hit   *inters;
    t_ray   local_ray;

    inters = ft_calloc(scene->n_elem, sizeof(t_hit));
    if (!inters)
        return (NULL);
    i = 0;
    while(i < scene->n_elem)
    {
        ray_transform_to_local(&scene->elem[i], ray, &local_ray);
        if (scene->elem[i].type == SP)
            inters[i] = sphere_intersection(local_ray, scene->elem[i]);
        else if (scene->elem[i].type == PL)
			inters[i] = plane_intersection(local_ray, scene->elem[i]);
        else if (scene->elem[i].type == CY)
			inters[i] = cylinder_intersection(local_ray, scene->elem[i]);
		i++;
    }
    return (inters);
}


t_comps prepare_computations(t_hit hit, t_ray ray)
{
	t_comps comps;
	float	bias;

	comps.t = hit_t(hit);
	comps.elem = hit.elem;
	comps.point = get_hit_point(ray, hit);
	comps.eyev = opp_vector(ray.vec);
	comps.normal = normal_at(comps.elem, comps.point);
	calc_inside(&comps);
	bias = EPSILON * get_object_scale(comps.elem);
	// bias = EPSILON * 1000;
	//bias = EPSILON;
	comps.over_point = new_lineal_point(comps.point, comps.normal, bias);
	return (comps);
}

float	get_object_scale(t_element elem)
{
    float	scale;
    t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
		
	axis_x = (t_vec){elem.tr_mat[0], elem.tr_mat[1], elem.tr_mat[2], VECTOR};
	axis_y = (t_vec){elem.tr_mat[4], elem.tr_mat[5], elem.tr_mat[6], VECTOR};
	axis_z = (t_vec){elem.tr_mat[7], elem.tr_mat[8], elem.tr_mat[9], VECTOR};
	scale = (magnitude(axis_x) + magnitude(axis_y) + magnitude(axis_z)) / 3.0f;
	return (scale);
}

void    calc_inside(t_comps *comps)
{
    if (dot_product(comps->normal, comps->eyev) < EPSILON)
    {
        comps->normal = opp_vector(comps->normal);
        comps->inside = true; 
    }
    else
        comps->inside = false;
    return ;
}

float shade_hit(t_data *scene, t_comps comps)
{
    int shadowed;

    shadowed = is_shadowed(scene, comps.over_point);
    return (lightning(scene, comps, shadowed));
}


