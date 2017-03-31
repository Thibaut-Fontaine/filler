/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:29:47 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/31 03:47:02 by tfontain         ###   ########.fr       */
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

int			leftup_piece(t_array *t)
{
	size_t	k;
	size_t	i;

	k = 0;
	while (k < t->szpiece.y)
	{
		i = 0;
		while (i < t->szpiece.x)
		{
			if (ft_tolower(t->plateau[k][i]) == ft_tolower(t->j))
				;
			++i;
		}
		++k;
	}
	t->piece;
	t->szpiece;
	
}

int			solver(t_array t)
{
	
	return (0);
}
