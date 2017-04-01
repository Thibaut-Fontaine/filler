/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/01 05:49:05 by tfontain         ###   ########.fr       */
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
	while (i < size && array[i][column] != c)
		++i;
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
	while (i < size && array[line][i] != c)
		++i;
	return (i < size);
}

/*
** decale le plus a gauche possible en supprimant le premier
** caractere de chaque ligne
*/

int			delete_left(char **array, int *size)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_memmove(array[i], array[i] + 1, *size);
		++i;
	}
	--*size;
	return (0);
}

/*
** remplace le dernier caractere de chaque ligne par un zero
*/

int			delete_right(char **array, int *size)
{
	int		i;

	i = 0;
	while (array[i])
	{
		array[i][*size] = 0;
		++i;
	}
	--*size;
	return (0);
}

/*
** decale le plus en haut possible en supprimant la premiere ligne + free
*/

int			delete_up(char **array, int *size)
{
	int		i;

	free(array[0]);
	i = 0;
	while (i < *size)
	{
		array[i] = array[i + 1];
		++i;
	}
	--*size;
	return (0);
}

/*
** free et supprime la derniere ligne
*/

int			delete_down(char **array, int *size)
{
	free(array[*size - 1]);
	array[*size - 1] = NULL;
	--*size;
	return (0);
}


/*
** decale la piece le plus en haut a gauche possible, tout en reduisant
** la taille szpiece a chaque decalage
*/

int			leftup_piece(t_array *t)
{
	while (check_line(t->piece, 0, t->j, t->szpiece.x) == 0)
		delete_up(t->piece, &(t->szpiece.y));
	while (check_column(t->piece, 0, t->j, t->szpiece.y) == 0)
		delete_left(t->piece, &(t->szpiece.x));
	while (check_line(t->piece, t->szpiece.y - 1, t->j, t->szpiece.x) == 0)
		delete_down(t->piece, &(t->szpiece.y));
	while (check_column(t->piece, t->szpiece.x - 1, t->j, t->szpiece.y) == 0)
		delete_right(t->piece, &(t->szpiece.x));
	return (1);
}

int			solver(t_array t)
{
	
	return (0);
}
