/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/07 04:26:37 by tfontain         ###   ########.fr       */
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
	--size;
	while (array[i][column] && i < size && array[i][column] != c)
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
	leftup_piece(t);
	printarray(t->piece);
	//check_place(*t, 1, 1);
	return (r);
}
