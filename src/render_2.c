/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:19:50 by aolabarr          #+#    #+#             */
/*   Updated: 2025/05/03 14:03:32 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	put_color_pixel(t_data *scene, t_image img, int x, int y)
{
	int		offset;
	t_ray	ray;
	t_color	amb;
	t_color	lig;
	t_color	color;

	compute_lighting(scene, &amb, &lig);
	init_pong_parameters(scene);
	ray = create_ray(scene, img, x, y);
	color = compute_color_for_pixel(scene, ray, amb, lig);
	offset = (img.line_len * y) + x * (img.bpp / 8);
	*(int *)((char *)img.addr + offset) = rgb_to_hex(color);
}

void	compute_lighting(t_data *scene, t_color *amb_all, t_color *lig_all)
{
	*amb_all = mult_color_scalar(scene->amb.color, scene->amb.ratio);
	*lig_all = mult_color_scalar(scene->lig.color, scene->lig.bright);
}

t_color	compute_color_for_pixel(t_data *sc, t_ray ray, t_color amb, t_color lig)
{
	t_hit		hit;
	t_hit		*inters;
	t_comps		comps;
	t_color		res_color;

	inters = intersect_world(ray, sc);
	hit = find_hit(sc, inters);
	free(inters);
	if (!hit.hit)
		return (SKY_BLUE);
	comps = prepare_computations(hit, ray);
	res_color = hadamard_product(add_colors(amb, lig), comps.elem.color);
	return (add_color_intensity(res_color, shade_hit(sc, comps)));
}
