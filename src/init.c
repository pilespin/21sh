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
#include <term.h>

t_st	*ft_init_struct(char **environ)
{
	t_st	*e;

	ft_start_termcaps();
	e = (t_st *)malloc(sizeof(t_st));
	e->env = ft_tabdup(environ);
	e->move_left = tgetstr("le", NULL);
	e->move_right = tgetstr("nd", NULL);
	e->hide_cursor = tgetstr("vi", NULL);
	e->show_cursor = tgetstr("ve", NULL);
	e->str_copy = ft_strnew(1);
	e->prompt = ft_strnew(1);
	e->random_color_prompt = FALSE;
	e->color_prompt = 3;
	e->in_heredoc = FALSE;
	e->kill_heredoc = FALSE;
	e->history = NULL;
	e->fd_0 = dup(0);
	e->fd_1 = dup(1);
	e->fd_2 = dup(2);
	ft_close_termcaps();
	return (e);
}

t_term	*ft_init_struct_term(t_st *e, char *prompt)
{
	t_term	*t;

	t = (t_term *)malloc(sizeof(t_term));
	t->history = e->history;
	t->goinhistory = 0;
	t->end_list_inhistory = 0;
	t->res = ft_strnew(1);
	if (!prompt)
	{
		free(e->prompt);
		e->prompt = ft_get_prompt(e);
	}
	t->res_tmp = NULL;
	t->i = 0;
	t->imax = 0;
	ft_refresh_line(e, t, 0);
	return (t);
}
