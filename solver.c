/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/06 18:00:54 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int			check_place(t_array t, size_t y, size_t x)
{
	size_t	k;
	size_t	i;

	k = 0;
	while (k < t.szpiece.y)
	{
		i = 0;
		while (i < t.szpiece.x)
		{
			if (ft_tolower(t.plateau[k][i]) == ft_tolower(t.j))
				;
			++i;
		}
		++k;
	}
	return (0);
}

/*
** verifie si le caractere specifie est present dans telle colonne d'un tableau
** (colonnes allant de [0] a [y])
*/

int			check_column(char **array, size_t column, char c, size_t size)
{
	size_t	i;

	i = 0;
	--size;
	while (array[i][column] && i < size && array[i][column] != c)
		++i;
	if (array[i][column] == 0)
		return (-1);
	return (i < size);
}


/*
** verifie si le caractere specifie est present dans telle ligne d'un tableau
** (lignes allant de [0] a [x])
*/

int			check_line(char **array, size_t line, char c, size_t size)
{
	size_t	i;

	i = 0;
	while (array[line][i] && i < size && array[line][i] != c)
		++i;
	if (array[line][i] == 0)
		return (-1);
	return (i < size);
}

int			solver(t_array t)
{
	
	return (0);
}
