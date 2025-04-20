/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:59:32 by binary            #+#    #+#             */
/*   Updated: 2025/04/20 23:28:22 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int all_components_scene(t_data *scene)
{
    if (scene->has_amb == FALSE)
        return (handle_error(ERR_AMB), EXIT_FAILURE);
    if (scene->has_cam == FALSE)
        return (handle_error(ERR_CAM), EXIT_FAILURE);
    if (scene->has_lig == FALSE)
        return (handle_error(ERR_LIG), EXIT_FAILURE);
    if(is_zero(scene->lig.bright) && is_zero(scene->amb.ratio))
        return (handle_error(ERR_DARK), EXIT_FAILURE);
    if (scene->n_elem == 0)
        return (handle_error(ERR_ELEM), EXIT_FAILURE);
    else
        return (EXIT_SUCCESS);
} 