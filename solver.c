/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/11 18:34:47 by tfontain         ###   ########.fr       */
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
	char	adv;

	adv = t.j == 'O' ? 'X' : 'O';
	dy = 0;
	n = 0;
	while (dy < t.szpiece.y)
	{
		if (t.plateau[y + dy] == NULL)
			return (0);
		dx = 0;
		while (dx < t.szpiece.x)
		{
			if (t.plateau[y + dy][x + dx] == 0)
				return (0);
			if (t.piece[dy][dx] == '*')
			{
				if (t.plateau[y + dy][x + dx] == t.j)
					++n;
				else if (t.plateau[y + dy][x + dx] == adv)
					return (0);
			}
			++dx;
		}
		++dy;
	}
	return (n == 1);
}

/*
** for each case, test if the piece can be placed at these coordonates.
** return the best ones.
*/

t_size		solver(t_array *t)
{
	t_size	r;
	t_size	ret;
	t_size	decal;

	ret.y = 0;
	ret.x = 0;
	decal = leftup_piece(t);
	if (decal.x == -1 || decal.y == -1)
		return (ret);
	r.y = 0;
	while (r.y < t->szplateau.y && t->plateau[r.y])
	{
		r.x = 0;
		while (r.x < t->szplateau.x && t->plateau[r.y][r.x])
		{
			if (check_place(*t, r.y, r.x) == 1)
			{
				ret.y = r.y - decal.y; // ret become the new "best" piece
				ret.x = r.x - decal.x; // remplir une liste avec tout
			}
			++r.x;
		}
		++r.y;
	}
	return (ret);
}
