/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/06 18:10:43 by tfontain         ###   ########.fr       */
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
		dprintf(2, "%s\n", array[i]);
		++i;
	}
}

int				main()
{
	t_array		array;

//	while (1)
//	{
		parse_input(&array);
		if ((array.piece == NULL || array.piece == NULL)
				&& ft_putstr_fdr("0 0\n", 1))
//			break ;
		printarray(array.plateau);
//	}


	//while (1)
	//	ft_putstr("12 14\n");
	return (0);
}
