/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachneartest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:02:39 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/11 20:52:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void			printarray(char **array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		dprintf(1, "%s\n", array[i]);
		++i;
	}
	dprintf(1, "- - - - - - - - - - - -\n");
}

int				main()
{
	t_array		t;
	t_list		*adv;
	t_size		p;

	t.plateau = malloc(9 * sizeof(char*));
	t.plateau[0] = malloc(25 + 1);
	strcpy(t.plateau[0], ".........................");
	t.plateau[1] = malloc(25 + 1);
	strcpy(t.plateau[1], ".X.......................");
	t.plateau[2] = malloc(25 + 1);
	strcpy(t.plateau[2], ".........................");
	t.plateau[3] = malloc(25 + 1);
	strcpy(t.plateau[3], ".........................");
	t.plateau[4] = malloc(25 + 1);
	strcpy(t.plateau[4], "..........OOOOO..........");
	t.plateau[5] = malloc(25 + 1);
	strcpy(t.plateau[5], "..........OOOOO..........");
	t.plateau[6] = malloc(25 + 1);
	strcpy(t.plateau[6], "..........OOOOO......XX..");
	t.plateau[7] = malloc(25 + 1);
	strcpy(t.plateau[7], "..........OOOOO..........");
	t.plateau[8] = NULL;

	t.j = 'X';
	printarray(t.plateau);
	adv = fill_points(t.plateau, t.j == 'X' ? 'O' : 'X');
	p = reach_nearest(t, adv);
	printf("y:%d x:%d\n", p.y, p.x);
	if (p.x == -666 || p.y == -666)
		printf("\nERROR\n");
	else
	{
		t.plateau[p.y][p.x] = 'P';
	}
	printarray(t.plateau);
	return (0);
}
