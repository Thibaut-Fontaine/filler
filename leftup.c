/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:41:48 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/07 20:59:52 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

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
	int		r;

	r = 0;
	while (r < t->szpiece.y)
	{
		if (ft_strnchr(t->piece[r], '*', t->szpiece.x))
		{
			r = -1;
			break ;
		}
		++r;
	}
	if (r != -1)
		return (-1);
	while (check_line(t->piece, 0, '*', t->szpiece.x) == 0)
		delete_up(t->piece, &(t->szpiece.y));
	while (check_column(t->piece, 0, '*', t->szpiece.y) == 0)
		delete_left(t->piece, &(t->szpiece.x));
	while (check_line(t->piece, t->szpiece.y - 1, '*', t->szpiece.x) == 0)
		delete_down(t->piece, &(t->szpiece.y));
	return (1);
}
