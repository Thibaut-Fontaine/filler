/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/09 00:06:45 by tfontain         ###   ########.fr       */
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

int			check_place(t_array t, size_t y, size_t x)
{
	int		n;
	int		dy;
	int		dx;

	--x;
	dy = 0;
	n = 0;
	while (dy < t.szpiece.y)
	{
		dx = 0;
		while (dx < t.szpiece.x) // checker si on depasse pas le plateau
		{
			if (t.plateau[y + dy][x + dx] == t.j && t.piece[dy][dx] == '*')
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
	r.y = 0;
	while (r.y < t->szplateau.y)
	{
		r.x = 0;
		while (r.x < t->szplateau.x)
		{
			if (check_place(*t, r.y, r.x) == 1)
				; // alors r.y et r.x sont des coordonnees viables
			++r.x;
		}
		++r.y;
	}
	return (r);
}
