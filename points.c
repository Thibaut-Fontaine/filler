/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:29:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/12 23:38:28 by tfontain         ###   ########.fr       */
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

	i(&(z.y), 0) && i(&(z.x), 0) && l(&head, ft_lstnew(&z, sizeof(t_size)))
		&& l(&o, head);
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
** if the player already touch the ennemy, it will play to the rightest place
** return -666 && -666 if one of the list == NULL (means error)
*/

void		rightest_only(float *dist, t_size *ret, t_size pla, float tmp)
{
	if (*dist > 1 || ret->x == -666 ||
			pla.x > ret->x)
	{
		*ret = pla;
		*dist = tmp;
	}
}

t_size		reachn(t_list **hpla, t_list **hadv, t_size ret)
{
	float	dist;
	float	tmp;
	t_list	*adv;
	t_list	*pla;

	adv = *hadv;
	pla = *hpla;
	dist = 99999999;
	while (pla != NULL)
	{
		adv = *hadv;
		while (adv != NULL)
		{
			if (dist > (tmp = distance(*((t_size*)pla->content),
							*((t_size*)adv->content))))
				rightest_only(&dist, &ret, *((t_size*)pla->content), tmp);
			adv = adv->next;
		}
		pla = pla->next;
	}
	freelist(hadv) && freelist(hpla);
	return (ret);
}

t_size		reach_nearest(t_array t, t_list *pla)
{
	t_list	*adv;
	t_size	ret;

	adv = fill_points(t.plateau, t.j == 'O' ? 'X' : 'O');
	ret.x = -666;
	ret.y = -666;
	if (pla == NULL || adv == NULL)
	{
		if (pla == NULL)
			freelist(&pla);
		if (adv == NULL)
			freelist(&adv);
		return (ret);
	}
	return (reachn(&pla, &adv, ret));
}

/*
** note : remove the second most left 'if' to only play at the nearest
*/
