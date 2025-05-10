/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:59:32 by binary            #+#    #+#             */
/*   Updated: 2025/05/10 15:25:06 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	all_components_scene(t_data *scene)
{
	if (scene->has_amb == 0)
		return (handle_error(ERR_MISS_ELEM), EXIT_FAILURE);
	if (scene->has_amb > 1)
		return (handle_error(ERR_DUPL_ELEM), EXIT_FAILURE);
	if (scene->has_cam == 0)
		return (handle_error(ERR_MISS_ELEM), EXIT_FAILURE);
	if (scene->has_cam > 1)
		return (handle_error(ERR_DUPL_ELEM), EXIT_FAILURE);
	if (scene->has_lig == 0)
		return (handle_error(ERR_MISS_ELEM), EXIT_FAILURE);
	if (scene->has_lig > 1)
		return (handle_error(ERR_DUPL_ELEM), EXIT_FAILURE);
	if (is_zero(scene->lig.bright) && is_zero(scene->amb.ratio))
		return (handle_error(ERR_DARK), EXIT_FAILURE);
	if (scene->n_elem == 0)
		return (handle_error(ERR_MISS_ELEM), EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(str + len - 3, ".rt", 3))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	vector_isequal(t_vec v1, t_vec v2)
{
	if (is_equal(v1.x, v2.x)
		&& is_equal(v1.y, v2.y)
		&& is_equal(v1.z, v2.z))
		return (TRUE);
	return (FALSE);
}
