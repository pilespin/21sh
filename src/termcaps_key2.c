/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 21:17:31 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>
#include <term.h>

int		ft_key_up_history(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__UP)
	{
		if (t->history && !t->end_list_inhistory)
		{
			if (t->goinhistory)
			{
				if (t->history->next)
				{
					t->history = t->history->next;
					t->end_list_inhistory = 0;
				}
				else
					t->end_list_inhistory = 1;
			}
			else
				t->res_tmp = ft_strdup(t->res);
			t->goinhistory = 1;
			ft_clear_line(e, t);
			ft_put_line(t, t->history->line);
		}
	}
	else
		return (1);
	return (0);
}

int		ft_key_down_history(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__DOWN)
	{
		t->end_list_inhistory = 0;
		if (t->history && t->history->prec)
		{
			t->history = t->history->prec;
			ft_clear_line(e, t);
			ft_put_line(t, t->history->line);
		}
		else if (t->goinhistory == 1 && !t->history->prec)
		{
			t->goinhistory = 0;
			ft_clear_line(e, t);
			ft_put_line(t, t->res_tmp);
			free(t->res_tmp);
		}
	}
	else
		return (1);
	return (0);
}

int		ft_key_left_right(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__RIGHT)
		ft_refresh_line(e, t, 0);
	else if (*(int*)t->buf == KEY__LEFT)
		ft_move_left(e, t);
	else
		return (1);
	return (0);
}

int		ft_key_copy_and_paste(t_st *e, t_term *t)
{
	size_t i;

	if (*(int*)t->buf == KEY__CTRL_P)
	{
		if (ft_strlen(e->str_copy) > 0)
		{
			ft_add_str_in_str(e, t, e->str_copy);
			i = 0;
			while (++i < ft_strlen(e->str_copy))
				ft_move_right(e, t);
		}
	}
	else if (*(int*)t->buf == KEY__CTRL_Y)
	{
		free(e->str_copy);
		e->str_copy = ft_strdup(t->res);
	}
	else
		return (1);
	return (0);
}
