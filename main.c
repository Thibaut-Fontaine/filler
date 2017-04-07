/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/07 01:57:06 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		printarray(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		dprintf(2, "%s\n", array[i]); // +4 pour lire le plateau
		++i;
	}
	dprintf(2, "- - - - - - - - - - - -\n");
}

int				main()
{
	t_array		t;
	t_size		to_write;

	while (1)
	{
		parse_input(&t);
		if ((t.piece == NULL || t.piece == NULL) && ft_putstr_fdr("0 0\n", 1))
			break ;
		decalleft(&t);
		to_write = solver(&t);
	}


	//while (1)
	//	ft_putstr("12 14\n");
	return (0);
}
