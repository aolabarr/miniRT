/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:36 by beiglesi          #+#    #+#             */
/*   Updated: 2025/04/26 13:24:22 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

int handle_error(int error)
{
	//ft_printf("Error\n");
	if (error == ERR_ARG)
		ft_putendl_fd(ERR_MSG_ARG, STDOUT_FILENO);
	if (error == ERR_EXT)
		ft_putendl_fd(ERR_MSG_EXT, STDOUT_FILENO);
	if (error == ERR_FD)
		ft_putendl_fd(ERR_MSG_FD, STDOUT_FILENO);
	if (error == ERR_SCENE)
		ft_putendl_fd(ERR_MSG_SCENE, STDOUT_FILENO);
	if (error == ERR_DARK)
		ft_putendl_fd(ERR_MSG_DARK, STDOUT_FILENO);
	if (error == ERR_AMB)
		ft_putendl_fd(ERR_MSG_AMB, STDOUT_FILENO);
	if (error == ERR_CAM)
		ft_putendl_fd(ERR_MSG_CAM, STDOUT_FILENO);
	if (error == ERR_LIG)
		ft_putendl_fd(ERR_MSG_LIG, STDOUT_FILENO);
	if (error == ERR_ELEM)
		ft_putendl_fd(ERR_MSG_ELEM, STDOUT_FILENO);

	return (EXIT_FAILURE);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	return (0);
}

int	valid_str(char *str)
{
	int i;

	i = 1;
	if (!str)
		return(1);
	if(is_element(str))
	{
		i = 2;
	}
	while(str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' \
			|| str[i] == '-' || is_space(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	get_position(char *str, t_coord *pos)
{
	char **temp;

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

t_eltype get_elem_type(char *str)
{
	if (ft_strncmp(str, "sp", 2) == 0)
		return (SP);
	if (ft_strncmp(str, "cy", 2) == 0)
		return (CY);
	if (ft_strncmp(str, "pl", 2) == 0)	
		return (PL);
	else
		return (handle_error(ERR_ELEM), UNKOWN);
}

int is_element(char *str)
{
	if (!ft_strncmp(str, "sp", 2) || !ft_strncmp(str, "cy", 2) || !ft_strncmp(str, "pl", 2))
		return (1);
	else
		return (0);
}
void	*ft_memsetf(void *b, float c, int len)
{
	float	*str;
	int	i;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
void	*ft_callocf(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memsetf(ptr, 0.0, size);
	return (ptr);
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

char	**ft_free_mat_n(char **mat, size_t mlen)
{
	while (mlen)
	{
		free(mat[mlen]);
		mlen--;
	}
	free(mat[0]);
	free(mat);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	aux;
	char	*str;

	aux = (char)c;
	c = aux;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}
