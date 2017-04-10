/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 05:14:04 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void			printarray(char **array) // a virer
{
	int			i;

	i = 0;
	while (array[i])
	{
		dprintf(2, "%s\n", array[i]);
		++i;
	}
	dprintf(2, "- - - - - - - - - - - -\n");
}

int				send_response(int y, int x)
{
	int			ret;

	ret = ft_putnbr_fdr(y, OUTPUT);
	ret += ft_putchar_fdr(' ', OUTPUT);
	ret += ft_putnbr_fdr(x, OUTPUT);
	ret += ft_putchar_fdr('\n', OUTPUT);
	return (ret);
}

int				main(void)
{
	t_array		t;
	t_size		to_write;

	while (1)
	{
		parse_input(&t);
		if ((t.piece == NULL || t.piece == NULL) && ft_putstr_fdr("0 0\n", 1))
			break ;
		decalleft(&t); // pour free il faut redecaler a droite
		to_write = solver(&t);
		send_response(to_write.y, to_write.x);
	}
	return (0);
}
