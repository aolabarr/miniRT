/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binary <binary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:21:22 by binary            #+#    #+#             */
/*   Updated: 2025/02/19 12:00:56 by binary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int normalized_vector(t_vector vec)
{
    int norm;

    norm = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (norm == 1)
        return (1);
    return (0);
}

int len_mat(char **str)
{
	int	i;

	if (!str)
        return (0);
    i = 0;
	while (str[i])
        i++;
    return (i);
}

