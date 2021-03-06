/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:41:48 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 05:12:14 by tfontain         ###   ########.fr       */
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
	return (1);
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
	return (1);
}

/*
** free et supprime la derniere ligne
*/

int			delete_down(char **array, int *size)
{
	free(array[*size - 1]);
	array[*size - 1] = NULL;
	--*size;
	return (1);
}

/*
** decale la piece le plus en haut a gauche possible, tout en reduisant
** la taille szpiece a chaque decalage
** return le decalage effectue.
*/

t_size		leftup_piece(t_array *t)
{
	int		r;
	t_size	decal;

	decal.x = -1;
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
		return (decal);
	decal.x = 0;
	decal.y = 0;
	while (check_line(t->piece, 0, '*', t->szpiece.x) == 0)
		++decal.y && delete_up(t->piece, &(t->szpiece.y));
	while (check_column(t->piece, 0, '*', t->szpiece.y) == 0)
		++decal.x && delete_left(t->piece, &(t->szpiece.x));
	while (check_line(t->piece, t->szpiece.y - 1, '*', t->szpiece.x) == 0)
		delete_down(t->piece, &(t->szpiece.y));
	return (decal);
}
