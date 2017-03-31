/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/31 01:38:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int				main()
{
	t_array		array;

	while (1)
	{
		parse_input(&array);
		if (array.piece == NULL || array.piece == NULL)
		{
			ft_putstr("0 0\n");
			break ;
		}
		ft_putstr("12 14\n");
	}


	//while (1)
	//	ft_putstr("12 14\n");
	return (0);
}
