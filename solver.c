/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/08 23:30:17 by tfontain         ###   ########.fr       */
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

/*
** check if the t->piece can be placed on the t->plateau
** at the y, x coordonates, or not. (return 1 for yes and 0 for no)
*/

int			check_place(t_array *t, size_t y, size_t x)
{
	int		n;
	int		dy;
	int		dx;

	--x;
	dy = 0;
	n = 0;
	while (dy < t->szpiece.y)
	{
		dx = 0;
		while (dx < t->szpiece.x)
		{
			if (t->plateau[y + dy][x + dx] == t->j && t->piece[dy][dx] == '*')
				++n;
			++dx;
		}
		++dy;
	}
	return (n == 1);
}

t_size		solver(t_array *t)
{
	t_size	r;

	r.x = 0;
	r.y = 0;
	if ((leftup_piece(t)) == -1)
		return (r);
	r.x = 15;
	r.y = 12; // segfault
	dprintf(2, "|%c|\n", t->j);
	dprintf(2, "can it be placed at y = %d && x = %d ? -|%d|-\n", r.y, r.x, check_place(t, r.y, r.x));
	printarray(t->plateau);
	printarray(t->piece);
	return (r);
}
