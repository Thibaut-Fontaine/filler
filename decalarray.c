/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decalarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 01:26:09 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/11 21:47:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void		decalleft(t_array *t)
{
	int		i;

	i = 0;
	while (t->plateau[i])
	{
		t->plateau[i] += 4;
		++i;
	}
}

void		decalright(t_array *t)
{
	int		i;

	i = 0;
	while (t->plateau[i])
	{
		t->plateau[i] -= 4;
		++i;
	}
}

int			freearray(char **array, t_size sz)
{
	while (*array && sz.y)
	{
		free(*array);
		++array;
		--sz.y;
	}
	return (1);
}
