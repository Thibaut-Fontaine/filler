/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/31 21:18:11 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

check_place(t_array t, size_t y, size_t x)
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
}

/*
** verifie si le caractere specifie est present dans telle colonne d'un tableau
** (colonnes allant de [0] a [y])
*/

int			check_column(char **array, size_t column, char c)
{
	size_t	i;

	i = 0;
	while (array[column] && array[i][column] != c)
		++i;
	return (array[i][column] == c);
}


/*
** verifie si le caractere specifie est present dans telle ligne d'un tableau
** (lignes allant de [0] a [x])
*/

int			check_line(char **array, size_t line, char c)
{
	size_t	i;

	i = 0;
	while (array[line][i] && array[line][i] != c)
		++i;
	return (array[line][i] == c);
}

/*
** decale la piece le plus en haut a gauche possible, tout en reduisant
** la taille szpiece a chaque decalage
*/

int			leftup_piece(t_array *t)
{
	size_t	y;
	size_t	x;
	
	while (t->piece[y][x])
	{
	x = 0;
	while (t->piece[y][x])
	{
		if (check_line(t->piece, y, t->j) == 0)
			;
		if (check_column(t->piece, x, t->j) == 0)
			;
		++x;
	}
	}
}

int			solver(t_array t)
{
	
	return (0);
}
