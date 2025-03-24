/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:06:13 by aolabarr          #+#    #+#             */
/*   Updated: 2025/03/24 20:27:54 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int   init_trans_matrix(t_data *scene)
{
    int i;

    i = 0;
    while(i < scene->n_elem)
    {
        if (get_trans_matrix(&scene->elem[i]))
            return (EXIT_FAILURE);
        if (get_trans_inv_matrix(&scene->elem[i]))
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}
int    get_trans_matrix(t_element *elem)
{
    //float mat1[16];
    //float mat2[16];

    elem->tr_mat = ft_calloc(16, sizeof(float));
    if(!elem->tr_mat)
        return (EXIT_FAILURE);
    scale_matrix(elem->radio, elem->radio, elem->radio, elem->tr_mat);
	//translation_matrix(elem->pos, mat2);
	//multiply_matrix(mat2, mat1, elem->tr_mat);
    return (EXIT_SUCCESS);
}

int    get_trans_inv_matrix(t_element *elem)
{
    //float mat1[16];
    //float mat2[16];

    elem->tri_mat = ft_calloc(16, sizeof(float));
    if(!elem->tri_mat)
        return (EXIT_FAILURE);
    scale_matrix(1 / elem->radio, 1 / elem->radio, 1 / elem->radio, elem->tri_mat);
	//translation_matrix(scalar_product(elem->pos, -1), mat2);
	//multiply_matrix(mat1, mat2, elem->tri_mat);
    return (EXIT_SUCCESS);
}
