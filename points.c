/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:29:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/11 21:20:34 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** free() the lists
*/

int			freelist(t_list **h)
{
	t_list	*current;
	t_list	*next;

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*h = NULL;
	return (1);
}

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
** to get the two nearest points, then return the player's one.
** return -666 && -666 if one of the list == NULL (means error)
*/

t_size		reach_nearest(t_array t, t_list *pla)
{
	float	dist;
	float	tmp;
	t_list	*adv;
	t_list	*hadv;
	t_list	*hpla;
	t_size	ret;

	adv = fill_points(t.plateau, t.j == 'O' ? 'X' : 'O');
	hadv = adv;
	hpla = pla;
	ret.x = -666;
	ret.y = -666;
	if (pla == NULL || adv == NULL)
	{
		if (pla == NULL)
			freelist(&hpla);
		if (adv == NULL)
			freelist(&hadv);
		return (ret);
	}
	dist = 99999999;
	while (pla != NULL)
	{
		adv = hadv;
		while (adv != NULL)
		{
			if (dist > (tmp = distance(*((t_size*)pla->content),
							*((t_size*)adv->content))))
			{
				ret = *((t_size*)pla->content);
				dist = tmp;
			}
			adv = adv->next;
		}
		pla = pla->next;
	}
	freelist(&hadv) && freelist(&hpla);
	return (ret);
}
