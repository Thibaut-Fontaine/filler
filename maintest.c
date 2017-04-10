/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 02:30:21 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 03:21:07 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include <stdio.h>
#include "./filler.h"

void	printarray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		++i;
	}
}

int		main(int argc, char *argv[])
{
	char	**array;
	t_array	t;

	array = malloc(10 * sizeof(char*));
	t.plateau = array;
	array[0] = ft_strnew(10);
	ft_strcpy(array[0], "..........");
	array[1] = ft_strnew(10);
	ft_strcpy(array[1], ".O........");
	array[2] = ft_strnew(10);
	ft_strcpy(array[2], "..........");
	array[3] = ft_strnew(10);
	ft_strcpy(array[3], "..........");
	array[4] = ft_strnew(10);
	ft_strcpy(array[4], ".......O..");
	array[5] = ft_strnew(10);
	ft_strcpy(array[5], "..........");
	array[6] = ft_strnew(10);
	ft_strcpy(array[6], "..........");
	array[7] = ft_strnew(10);
	ft_strcpy(array[7], "..........");
	array[8] = ft_strnew(10);
	ft_strcpy(array[8], "...L0L....");
	array[9] = NULL;

	t.szplateau.y = 9;
	t.szplateau.x = 10;
	t.j = 'O';
	t.piece = malloc(1 * sizeof(char*));
	t.piece[0] = ft_strnew(5);
	t.szpiece.y = 1;
	t.szpiece.x = 5;
	ft_strcpy(t.piece[0], "*....");
	printf("? -> |%d|", check_place(t, 1, 1));
	return (0);
}
