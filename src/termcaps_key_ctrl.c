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

int		ft_key_ctrl_z(t_st *e, t_term *t)
{
	int	z;

	if (*(int*)t->buf == KEY__CTRL_Z)
	{
		z = 0;
		while (t->i > 0 && t->res[t->i] == ' ')
			ft_move_left(e, t);
		while (t->i > 0 && (t->res[t->i] != ' ' || z == 0))
		{
			z++;
			ft_move_left(e, t);
		}
	}
	else
		return (1);
	return (0);
}

int		ft_key_ctrl_x(t_st *e, t_term *t)
{
	int z;

	if (*(int*)t->buf == KEY__CTRL_X)
	{
		z = 0;
		while (t->i < t->imax && t->res[t->i] == ' ')
			ft_move_right(e, t);
		while (t->i < t->imax && (t->res[t->i] != ' ' || z == 0))
		{
			z++;
			ft_move_right(e, t);
		}
		if (t->i == t->imax)
			ft_move_right(e, t);
	}
	else
		return (1);
	return (0);
}

int		ft_key_ctrl_l_k(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__CTRL_L)
	{
		ft_putstr(tgetstr("cl", NULL));
		ft_refresh_line(e, t, 0);
	}
	else if (*(int*)t->buf == KEY__CTRL_K)
	{
		ft_putstr(tgetstr("ce", NULL));
		t->tmp2 = ft_strndup(t->res, t->i);
		free(t->res);
		t->res = t->tmp2;
	}
	else if (*(int*)t->buf == KEY__CTRL_R)
	{
		e->random_color_prompt = !e->random_color_prompt;
	}
	else
		return (1);
	return (0);
}

int		ft_key_ctrl_d(t_term *t)
{
	if (*(int*)t->buf == KEY__CTRL_D)
	{
		ft_putstr("^D\n");
		if (t->goinhistory)
			free(t->res_tmp);
		free(t->res);
		free(t);
		return (1);
	}
	return (0);
}

int		ft_key_ctrl_c(t_st *e, t_term *t)
{
	if (*(int*)t->buf == KEY__CTRL_C)
	{
		ft_putstr("^C\n");
		if (e->in_heredoc)
			e->kill_heredoc = TRUE;
		if (t->goinhistory)
			free(t->res_tmp);
		free(t->res);
		free(t);
		return (1);
	}
	return (0);
}
