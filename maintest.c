/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 02:30:21 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/07 04:12:51 by tfontain         ###   ########.fr       */
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
	t.piece = array;
	array[0] = ft_strnew(10);
	ft_strcpy(array[0], "..........");
	array[1] = ft_strnew(10);
	ft_strcpy(array[1], "..........");
	array[2] = ft_strnew(10);
	ft_strcpy(array[2], "..........");
	array[3] = ft_strnew(10);
	ft_strcpy(array[3], "..........");
	array[4] = ft_strnew(10);
	ft_strcpy(array[4], ".......**.");
	array[5] = ft_strnew(10);
	ft_strcpy(array[5], "..........");
	array[6] = ft_strnew(10);
	ft_strcpy(array[6], "..........");
	array[7] = ft_strnew(10);
	ft_strcpy(array[7], "..........");
	array[8] = ft_strnew(10);
	ft_strcpy(array[8], "...L0L....");
	array[9] = NULL;

	t.szpiece.y = 9;
	t.szpiece.x = 10;
	t.j = 'O';
	printf("========== **array : \n");
	printarray(t.piece);
	printf("==========\n");
	printf("========== element supprime : \n");
	//
	leftup_piece(&t);
	//delete_right(t.piece, &(t.szpiece.x));
	//
	//
	printf("ok\n");
	printarray(t.piece);
	printf("==========\n");
	return (0);
}
