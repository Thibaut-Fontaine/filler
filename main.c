/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:19:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/28 22:23:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char	*tmp;
	char	c;

	if (argc != 2)
		return (0);
	fd = open("./ccc.txt", O_TRUNC | O_RDWR | O_CREAT, 0777);

	tmp = argv[1];
	if (ft_strcmp(argv[1], "$$$ exec p") == 0)
		argv[1] += 10;
	c = *(argv[1]);
	tmp = malloc(2);
	tmp[0] = c == '1' ? 'O' : 'X';
	tmp[1] = 0;
	dprintf(fd, "%s", tmp);
	return (0);
}
