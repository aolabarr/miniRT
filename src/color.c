/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/26 19:53:27 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minirt.h"

void testing_colors(t_data *scene)
{
    printf("AMBIENTE\n");
    printf("Color red: %d\n", (int)scene->amb.color.red);
    printf("Color green: %d\n", (int)scene->amb.color.green);
    printf("Color blue: %d\n", (int)scene->amb.color.blue);
    printf("Color HEX: 0X%0X\n", rgb_to_hex(scene->amb.color));
    printf("LIGHT\n");
    printf("Color red: %d\n", (int)scene->lig.color.red);
    printf("Color green: %d\n", (int)scene->lig.color.green);
    printf("Color blue: %d\n", (int)scene->lig.color.blue);
    printf("Color HEX: 0X%0X\n", rgb_to_hex(scene->lig.color));
}

t_color add_colors(t_color col1, t_color col2)
{
    t_color sum;
    sum.red = col1.red + col2.red;
    sum.green = col1.green + col2.green;
    sum.blue = col1.blue + col2.blue;
    return(sum);
}

t_color sub_colors(t_color col1, t_color col2)
{
    t_color sub;
    sub.red = col1.red - col2.red;
    sub.green = col1.green - col2.green;
    sub.blue = col1.blue - col2.blue;
    return(sub);
}

t_color hadamar_product(t_color col1, t_color col2)
{
    t_color hadamar;
    hadamar.red = col1.red * col2.red;
    hadamar.green = col1.green * col2.green;
    hadamar.blue = col1.blue * col2.blue;
    return(hadamar);
}

t_color mult_color_scalar(t_color col, float scalar)
{
    t_color mult;
    mult.red = col.red * scalar;
    mult.green = col.green * scalar;
    mult.blue = col.blue * scalar;
    return(mult);
}

