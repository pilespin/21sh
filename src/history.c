/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 20:33:16 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static t_history	*ft_create_new_link_history(char *line)
{
	t_history	*e;

	e = malloc(sizeof(t_history));
	e->line = ft_strdup(line);
	e->prec = NULL;
	e->next = NULL;
	return (e);
}

void				ft_add_in_history(t_st *e, char *line)
{
	t_history	*tmp;
	char		*newline;
	char		*line2;

	e->fd_file = open(HISTORY_NAME, O_RDWR | O_CREAT | O_APPEND, 0600);
	ft_putendl_fd(line, e->fd_file);
	close(e->fd_file);
	newline = ft_strchr(line, '\n');
	if (newline)
		line2 = ft_strsub(line, 0, ft_strlen(line) - ft_strlen(newline));
	else
		line2 = ft_strdup(line);
	if (!e->history)
	{
		e->history = ft_create_new_link_history(line2);
	}
	else
	{
		tmp = e->history;
		e->history = ft_create_new_link_history(line2);
		e->history->next = tmp;
		tmp->prec = e->history;
	}
	free(line2);
}
