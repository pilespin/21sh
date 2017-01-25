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

void	ft_clear_line(t_st *e, t_term *t)
{
	while (t->i-- > 0)
		ft_putstr(e->move_left);
	ft_putstr(tgetstr("ce", NULL));
}

void	ft_put_line(t_term *t, char *line)
{
	ft_putstr(line);
	ft_putstr(tgetstr("cd", NULL));
	t->i = ft_strlen(line);
	t->imax = t->i - 1;
	free(t->res);
	t->res = ft_strdup(line);
}

void	ft_refresh_line(t_st *e, t_term *t, int stayright)
{
	int z;
	int size;

	z = t->i;
	ft_clear_line(e, t);
	size = ft_strlen(e->prompt) + 10;
	while (size--)
		ft_putstr(e->move_left);
	if (e->random_color_prompt)
		e->color_prompt = ft_random(1, 7);
	ft_putstrc(e->color_prompt, 0, e->prompt);
	ft_put_line(t, t->res);
	if (!stayright)
	{
		while (z < t->i - 1)
			ft_move_left(e, t);
	}
}

void	ft_add_str_in_str(t_st *e, t_term *t, char *str)
{
	t->tmp = ft_insert_str_in_line(t->res, str, t->i, t->i - 1);
	free(t->res);
	t->res = t->tmp;
	t->imax = ft_strlen(t->tmp) - 1;
	ft_refresh_line(e, t, 0);
}

void	ft_putctrl(char ctrl)
{
	ft_putchar('^');
	ft_putchar(ctrl);
}
