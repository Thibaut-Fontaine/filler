/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/06 20:27:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void    printarray(char **array)
{
	int     i;

	i = 0;
	while (array[i])
	{
		dprintf(2, "%s\n", array[i] + 4); // +4 pour lire le plateau
		++i;
	}
	dprintf(2, "------------\n");
}

int				main()
{
	t_array		array;

	while (1)
	{
		parse_input(&array);
		if ((array.piece == NULL || array.piece == NULL)
				&& ft_putstr_fdr("0 0\n", 1))
		;
		
	}


	//while (1)
	//	ft_putstr("12 14\n");
	return (0);
}
