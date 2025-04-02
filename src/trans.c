/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:06:13 by aolabarr          #+#    #+#             */
/*   Updated: 2025/04/02 20:16:37 by aolabarr         ###   ########.fr       */
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
    float mat1[16];
    float mat2[16];

    ft_memsetf(&mat1, 0, 16);
    ft_memsetf(&mat2, 0, 16);
    elem->tr_mat = ft_callocf(16, sizeof(float));
    if(!elem->tr_mat)
        return (EXIT_FAILURE);
    scale_matrix(elem->radio, elem->radio, elem->radio, mat1);
	translation_matrix(elem->pos, mat2);
	multiply_matrix(mat2, mat1, elem->tr_mat);
    return (EXIT_SUCCESS);
}

int    get_trans_inv_matrix(t_element *elem)
{
    float mat1[16];
    float mat2[16];

    ft_memsetf(&mat1, 0, 16);
    ft_memsetf(&mat2, 0, 16);
    //printf("\nzeros"), print_matrix(mat1);
    elem->tri_mat = ft_callocf(16, sizeof(float));
    if(!elem->tri_mat)
        return (EXIT_FAILURE);
    //printf("center\n"), print_pos(elem->pos);
    scale_matrix(1 / elem->radio, 1 / elem->radio, 1 / elem->radio, mat1);
	translation_matrix(scalar_product(elem->pos, -1), mat2);
    //printf("\ntraslacion"), print_matrix(elem->tri_mat);
	multiply_matrix(mat1, mat2, elem->tri_mat);
    return (EXIT_SUCCESS);
}
