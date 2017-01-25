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

int		ft_key_page_up_and_down(t_st *e, t_term *t)
{
	int col;

	col = tgetnum("co");
	if (*(int*)t->buf == KEY__PAGE_UP && col > 1)
	{
		while (col--)
			ft_move_left(e, t);
	}
	else if (*(int*)t->buf == KEY__PAGE_DOWN && col > 1)
	{
		t->i += col - 1;
		if (t->i > t->imax)
			t->i = t->imax;
		ft_refresh_line(e, t, 0);
	}
	else
		return (1);
	return (0);
}

int		ft_key_home_and_end(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__HOME || *(int*)t->buf == KEY__CTRL_A)
	{
		while (t->i-- > 0)
			ft_putstr(e->move_left);
		t->i = 0;
	}
	else if (*(int*)t->buf == KEY__END || *(int*)t->buf == KEY__CTRL_E)
	{
		if (t->i < t->imax)
		{
			ft_refresh_line(e, t, 1);
			t->i = t->imax + 1;
		}
	}
	else
		return (1);
	return (0);
}

int		ft_key_backspace(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__BACKSPACE)
	{
		if (t->i > 0)
		{
			ft_move_left(e, t);
			t->tmp = ft_delete_str_in_line(t->res, t->i, t->i + 1);
			t->i--;
			free(t->res);
			t->res = t->tmp;
			t->imax = ft_strlen(t->res) - 1;
			ft_refresh_line(e, t, 0);
		}
	}
	else
		return (1);
	return (0);
}

int		ft_key_tabulation(t_st *e, t_term *t)
{
	(void)e;
	(void)t;
	if (*(int*)t->buf == KEY__TAB)
	{
	}
	else
		return (1);
	return (0);
}

char	*ft_key_return(t_term *t)
{
	char *tmp;

	if (*(int*)t->buf == KEY__RETURN)
	{
		ft_putchar(10);
		if (t->goinhistory)
			free(t->res_tmp);
		if (ft_strlen(t->res) > 0)
			tmp = ft_strdupf(t->res);
		else
		{
			free(t->res);
			tmp = ft_strnew(1);
		}
		free(t);
		return (tmp);
	}
	return (NULL);
}
