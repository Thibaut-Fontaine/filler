/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:20:10 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 16:34:02 by tfontain         ###   ########.fr       */
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

# define INPUT 0
# define OUTPUT 1

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

typedef union
{
	float		x;
	int			i;
}				t_sqrt;

void			decalleft(t_array *t);
void			printarray(char **array); // a virer
t_array			parse_input(t_array *array);
t_size			solver(t_array *t);
int				check_column(char **array, size_t column, char c, size_t size);
int				check_line(char **array, size_t line, char c, size_t size);
t_size			leftup_piece(t_array *t);
int				delete_left(char **array, int *size);
int				send_response(int y, int x);
int				check_place(t_array t, size_t y, size_t x);
float			distance(t_size a, t_size b);

#endif
