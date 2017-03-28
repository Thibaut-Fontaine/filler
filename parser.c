/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:14:48 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/28 19:45:02 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** if the reading line is the '$$$ exec', it will return *'O' or *'X'
** return the got string if its not the $$$exec line
** return NULL if error occured
*/

char			*get$$$execline()
{
	int			ret;
	char		*line;
	char		*tmp;
	char		c;

	if ((ret = get_next_line(INPUT, &line)) <= 0)
	{
		if (ret == 0)
			free(line);
		return (NULL);
	}
	tmp = line;
	if (ft_strcmp(line, "$$$ exec p") == 0)
		line += 10;
	else
		return (tmp);
	c = *line;
	free(tmp);
	tmp = malloc(2);
	tmp[0] = c == '1' ? 'O' : 'X';
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

char			**fill_memory(size_t y, size_t x)
{
	int			ret;
	char		**split;
	size_t		k;

	if ((split = malloc((y + 1) * sizeof(char*))) == NULL)
		return (NULL);
	k = 0;
	split[y] = NULL;
	while (k < y && (ret = get_next_line(INPUT, &(split[k]))) > 0
			&& ft_strlen(split[k]) == x)
		++k;
	if (ret == -1 || k != y - 1)
		return (NULL);
	return (split);
}

int				parse_input()
{
	char		*line;
	int			ret;
	t_size		sz;
	//char		**array;

	if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
		return (-1);
	free(line);
	if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
		return (-1);
	sz = getsize(line);
	free(line);
	if (sz.x == -1 || sz.y == -1)
		return (-1);
	if ((ret = get_next_line(INPUT, &line)) == -1 || ret == 0)
		return (-1);
	free(line);
	//if ((array = fill_memory(sz.y, sz.x)) == NULL)
	//	return (-1);
	//ggg(array);
	dprintf(fd, "%d ~ %d\n", sz.y, sz.x);
	return (0);
}
