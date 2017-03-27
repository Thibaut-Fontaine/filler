/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:36:22 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 00:48:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETLINE_H
# define GETLINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./../../libft/includes/libft.h"

# define BUFF_SIZE 2000

typedef struct		s_stack
{
	char			*pt;
	char			buff[BUFF_SIZE + 1];
	struct s_stack	*next;
}					t_stack;

typedef struct		s_head
{
	t_stack			*head;
	t_stack			*current;
	int				end;

}					t_head;

int					getline(const int fd, char **line);

#endif
