/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/17 13:48:15 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	add_colors(t_color col1, t_color col2)
{
	t_color	sum;

	sum.red = col1.red + col2.red;
	sum.green = col1.green + col2.green;
	sum.blue = col1.blue + col2.blue;
	return (sum);
}

// t_color sub_colors(t_color col1, t_color col2)
// {
//     t_color sub;
//     sub.red = col1.red - col2.red;
//     sub.green = col1.green - col2.green;
//     sub.blue = col1.blue - col2.blue;
//     return(sub);
// }

t_color	hadamard_product(t_color col1, t_color col2)
{
	t_color	hadamard;

	hadamard.red = clamp_color(col1.red * col2.red);
	hadamard.green = clamp_color(col1.green * col2.green);
	hadamard.blue = clamp_color(col1.blue * col2.blue);
	return (hadamard);
}

t_color	mult_color_scalar(t_color col, float scalar)
{
	t_color	mult;

	mult.red = col.red * scalar;
	mult.green = col.green * scalar;
	mult.blue = col.blue * scalar;
	return (mult);
}

int	rgb_to_hex(t_color col)
{
	int	hexcol;

	col.red = clamp_color((int)(col.red * 255));
	col.green = clamp_color((int)(col.green * 255));
	col.blue = clamp_color((int)(col.blue * 255));
	hexcol = ((int)(col.red) << 16) | ((int)(col.green) << 8) | (int)(col.blue);
	return (hexcol);
}

float	clamp_color(float color)
{
	if (color < MIN_RGB)
		return (MIN_RGB);
	if (color > MAX_RGB)
		return (MAX_RGB);
	return (color);
}
