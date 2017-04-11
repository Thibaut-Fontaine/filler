/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/11 20:58:19 by tfontain         ###   ########.fr       */
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
	t_list		*adv;

	while (1)
	{
		parse_input(&t);
		if ((t.piece == NULL || t.piece == NULL) && ft_putstr_fdr("0 0\n", 1))
			break ;
		decalleft(&t); // pour free il faut redecaler a droite
		adv = solver(&t);
		to_write = reach_nearest(t, adv);
		if (to_write.x == -666 || to_write.y == -666)
		{
			to_write.x = 0;
			to_write.y = 0;
		}
		dprintf(2, "%d %d\n", to_write.y, to_write.x);
		send_response(to_write.y, to_write.x);
		// il faut free la piece et le tableau.
	}
	return (0);
}
