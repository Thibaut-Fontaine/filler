/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/07 18:44:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** verifie si le caractere specifie est present dans telle colonne d'un tableau
** (colonnes allant de [0] a [y])
*/

int			check_column(char **array, size_t column, char c, size_t size)
{
	size_t	i;

	i = 0;
	while (array[i][column] && i < size)
	{
		if (array[i][column] == c)
			return (1);
		++i;
	}
	return (0);
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
	return (i < size);
}

int			check_place(t_array t, size_t y, size_t x)
{
	(void)t.szplateau.x;
	(void)(y + x);
	return (0);
}

t_size		solver(t_array *t)
{
	t_size	r;

	r.x = 0;
	r.y = 0;
	if ((leftup_piece(t)) == -1)
		return (r);
	printarray(t->plateau);
	printarray(t->piece);
	//check_place(*t, 1, 1);
	return (r);
}
