/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:20:10 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/06 19:20:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "./libft/includes/libft.h"
# include "./get_next_line.h"

# define INPUT 0 // mettre 0

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct
{
	char		j;
	t_size		szplateau;
	t_size		szpiece;
	char		**piece;
	char		**plateau;
}				t_array;

void			printarray(char **array); // a virer
t_array			parse_input(t_array *array);
int				solver(t_array t);
int				check_column(char **array, size_t column, char c, size_t size);
int				check_line(char **array, size_t line, char c, size_t size);
int				leftup_piece(t_array *t);
int				delete_left(char **array, int *size);

#endif
