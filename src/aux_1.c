/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:36 by beiglesi          #+#    #+#             */
/*   Updated: 2025/05/03 10:02:31 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	get_position(char *str, t_coord *pos)
{
	char	**temp;

	temp = ft_split(str, ',');
	if (len_mat(temp) != 3)
	{
		ft_free_mat(temp);
		return (ERR_SCENE);
	}
	pos->x = ft_atoif(temp[0]);
	pos->y = ft_atoif(temp[1]);
	pos->z = ft_atoif(temp[2]);
	pos->w = POINT;
	ft_free_mat(temp);
	return (EXIT_SUCCESS);
}

int	get_vector(char *str, t_coord *vec)
{
	char		**temp;

	temp = ft_split(str, ',');
	vec->x = ft_atoif(temp[0]);
	vec->y = ft_atoif(temp[1]);
	vec->z = ft_atoif(temp[2]);
	vec->w = VECTOR;
	ft_free_mat(temp);
	*vec = normalize(*vec);
	return (EXIT_SUCCESS);
}

char	**ft_split_allwhitespace(const char *s)
{
	char	**mat;
	size_t	i;
	size_t	mlen;
	size_t	slen;

	mlen = ft_word_count_allwhitespace(s);
	mat = malloc(sizeof(char *) * (mlen + 1));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < mlen)
	{
		while (is_space(*s))
			s++;
		slen = ft_char_count_allwhitespace(s);
		mat[i] = malloc(sizeof(char) * (slen + 1));
		if (!mat[i])
			return (ft_free_mat_n(mat, i));
		ft_strlcpy(mat[i], s, slen + 1);
		s += slen;
		i++;
	}
	mat[i] = NULL;
	return (mat);
}

size_t	ft_word_count_allwhitespace(const char *s)
{
	size_t	count;
	size_t	sw;

	if (!s)
		return (0);
	count = 0;
	sw = 0;
	while (*s != '\0')
	{
		if (is_space(*s))
			sw = 0;
		else if (sw == 0)
		{
			sw = 1;
			count++;
		}
		s++;
	}
	return (count);
}

size_t	ft_char_count_allwhitespace(const char *s)
{
	size_t	count;

	count = 0;
	while (!is_space(s[count]) && s[count] != '\0')
		count++;
	return (count);
}
