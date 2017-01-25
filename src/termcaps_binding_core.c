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

static int	ft_parse_binding(t_st *e, t_term *t)
{
	ft_read_line(t);
	ft_putstr(e->hide_cursor);
	if (ft_key_left_right(e, t) && ft_key_down_history(e, t) &&
		ft_key_up_history(e, t) && ft_key_ctrl_z(e, t) &&
		ft_key_ctrl_x(e, t) && ft_key_page_up_and_down(e, t) &&
		ft_key_home_and_end(e, t) && ft_key_backspace(e, t) &&
		ft_key_tabulation(e, t))
	{
		ft_putstr(e->show_cursor);
		return (1);
	}
	ft_putstr(e->show_cursor);
	return (0);
}

static void	ft_add_string_in_string(t_st *e, t_term *t, char *line)
{
	ft_putstr(e->hide_cursor);
	if (!line[1] && ft_strlen(t->res) < MAX_LINE_LENGHT)
		ft_add_str_in_str(e, t, line);
	ft_putstr(e->show_cursor);
}

static void	ft_free_struct_termcaps(t_term *t)
{
	free(t->res_tmp);
	free(t);
}

static char	*ft_parse_binding_else(t_st *e, t_term *t)
{
	if ((t->tmp = ft_key_return(t)))
		return (t->tmp);
	else if (ft_key_ctrl_d(t) || ft_key_ctrl_c(e, t))
	{
		if (e->kill_heredoc)
		{
			e->kill_heredoc = FALSE;
			return ((char *)-1);
		}
		return (NULL);
	}
	else
		ft_putctrl(t->buf[0] + 64);
	return ((char *)-10);
}

char		*ft_read_termcaps(t_st *e, char *prompt)
{
	t_term	*t;
	char	*tmp;

	t = ft_init_struct_term(e, prompt);
	while (1)
	{
		if (ft_parse_binding(e, t))
		{
			if (ft_isalpha(t->buf[0] + 96) && t->buf[1] == 0)
			{
				if (ft_key_copy_and_paste(e, t) && ft_key_ctrl_l_k(e, t))
				{
					tmp = ft_parse_binding_else(e, t);
					if ((int)tmp != -10)
						return (tmp);
				}
			}
			else
				ft_add_string_in_string(e, t, t->buf);
		}
	}
	ft_free_struct_termcaps(t);
	return (NULL);
}
