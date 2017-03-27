/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:27:02 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 00:37:11 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getline.h"

static int			ft_getlen(t_stack *current)
{
	char			*ch;
	int				len;

	len = 0;
	if (ft_strchr(current->pt, '\n') == NULL)
		len = ft_strlen(current->pt);
	while ((ch = ft_strchr(current->pt, '\n')) == NULL)
	{
		len += BUFF_SIZE;
		if ((current = current->next) == NULL)
			return (-1);
	}
	return (len += ch - current->pt);
}

static char			*ft_generate_line(t_stack **head, int len)
{
	char			*ch;
	char			*line;
	char			*line_head;

	line = malloc(len + 1);
	line_head = line;
	while ((ch = ft_strchr((*head)->pt, '\n')) == NULL)
	{
		ft_strcpy(line, (*head)->pt);
		line += ft_strlen((*head)->pt);
		ch = (void*)(*head);
		*head = (*head)->next;
		free((t_stack*)ch);
	}
	ft_strncpy(line, (*head)->pt, (len = ch - (*head)->pt));
	line[len] = 0;
	(*head)->pt = ch + 1;
	return (line_head);
}

static t_stack			*ft_generate_new(t_stack *current)
{
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = malloc(sizeof(t_stack));
		current = current->next;
	}
	else
		current = malloc(sizeof(t_stack));
	current->next = NULL;
	*(current->buff) = 0;
	current->pt = current->buff;
	return (current);
}

int						getline(const int fd, char **line)
{
	static t_head		head = {NULL, NULL, 0};
	int					r;
	int					len;

	r = BUFF_SIZE;
	while (r != 0 && r != -1)
	{
		head.current = ft_generate_new(head.head);
		if (head.head == NULL)
			head.head = head.current;
		if ((r = read(fd, head.current->buff, BUFF_SIZE)) == -1)
			return (-1);
		head.current->buff[r] = 0;
	}
	if ((len = ft_getlen(head.head)) == -1)
		return (0);
	*line = ft_generate_line(&head.head, len);
	return (1);
}
