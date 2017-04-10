/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:29:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 15:51:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** get all the points of the ennemy into a structure
*/

t_list		*fill_points(char **array, char c)
{
	t_list	*o;
	t_list	*head;
	t_size	z;

	z.y = 0;
	z.x = 0;
	head = ft_lstnew(&z, sizeof(t_size));
	o = head;
	while (array[z.y])
	{
		z.x = 0;
		while (array[z.y][z.x])
		{
			if (array[z.y][z.x] == c)
			{
				o->next = ft_lstnew(&z, sizeof(t_size));
				o = o->next;
			}
			++z.x;
		}
		++z.y;
	}
	o = head;
	head = head->next;
	free(o->content);
	free(o);
	return (head);
}

/*
** compare all the enemy points and the coordonates where we can place
** to get the two nearest points
*/

reach_nearest(t_array t, t_list *adv)
{
	t_list	*pla;
	float	dist;

	pla = fill_points(t.plateau, t.j);
	while (pla != NULL)
	{
		dist = distance(*(t_size*)(pla->content), *(t_size*)(adv->content));
		
	}
}
