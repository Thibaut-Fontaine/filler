/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:14:48 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/30 22:24:18 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** if the reading line is the '$$$ exec', it will return *'O' or *'X'
** return the got string if its not the $$$exec line
** return NULL if error occured
*/

char			*getexecline(void)
{
	int			ret;
	char		*line;
	char		*tmp;
	char		c;

	if ((ret = get_next_line(INPUT, &line)) <= 0)
		return (NULL);
	tmp = line;
	while (*tmp && ft_strncmp(tmp, "exec p", 6) != 0)
		++tmp;
	if (*tmp == 0)
		return (line);
	tmp += 6;
	c = *tmp;
	free(line);
	tmp = malloc(2);
	tmp[0] = (c == '1' ? 'O' : 'X');
	tmp[1] = 0;
	return (tmp);
}

/*
** take the 2nd line of the input
** get the size of the 2 dimensions array to read
** -> reach "Plateau (y) (x):"
** return the size, or -1 in at least y or x if an error occured
*/

t_size			getsize(const char *s)
{
	t_size		sz;

	sz.x = -1;
	sz.y = -1;
	while (*s)
	{
		if (*s && ft_isdigit(*s) && (sz.y = ft_atoi(s)))
		{
			while (*s && ft_isdigit(*s))
				++s;
			while (*s && !ft_isdigit(*s))
				++s;
			if (*s && ft_isdigit(*s) && (sz.x = ft_atoi(s)))
				return (sz);
		}
		++s;
	}
	return (sz);
}

/*
** return 2 dimensions array got like strsplit can do
** or return NULL if an error occured
*/

char			**fill_memory(size_t y)
{
	char		**ret;
	size_t		k;

	ret = malloc((y + 1) * sizeof(char*));
	k = 0;
	while (y > k)
		get_next_line(INPUT, &(ret[k++]));
	ret[k] = NULL;
	return (ret);
}

t_array			parse_input(t_array *array)
{
	char		*line;
	int			ret;

	array->plateau = NULL;
	array->piece = NULL;
	if ((line = getexecline()) == NULL)
		return (*array);
	else if (*line == 'O' || *line == 'X')
	{
		array->j = *line;
		free(line);
		if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
			return (*array);
	}
	array->szplateau = getsize(line);
	free(line);
	if (array->szplateau.x == -1 || array->szplateau.y == -1)
		return (*array);
	if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
		return (*array);
	free(line);
	if ((array->plateau = fill_memory(array->szplateau.y)) == NULL)
		return (*array);
	if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
		return (*array);
	array->szpiece = getsize(line);
	free(line);
	if (array->szpiece.x == -1 || array->szpiece.y == -1)
		return (*array);
	if ((array->piece = fill_memory(array->szpiece.y)) == NULL)
		return (*array);
	return (*array);
}
