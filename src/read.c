/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 21:36:52 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void			ft_read_line(t_term *t)
{
	ft_memset(t->buf, 0, MAX_READ_TERM);
	read(STDIN, t->buf, MAX_READ_TERM);
}

char			*ft_read_in_stdin(t_st *e)
{
	char	*line;
	char	*line2;
	int		ret;

	ft_start_termcaps();
	line = ft_read_termcaps(e, NULL);
	ft_close_termcaps();
	if (line && ft_strlen(line) <= 0)
	{
		free(line);
		return (NULL);
	}
	while ((ret = ft_check_dquote_or_else(line)))
	{
		ft_get_quote_prompt(e, ret);
		ft_start_termcaps();
		line2 = ft_read_termcaps(e, e->prompt);
		ft_close_termcaps();
		line = ft_strjoinf(line, "\n", 1);
		line = ft_strjoinf(line, line2, 1);
		free(line2);
	}
	return (line);
}

static char		*ft_read_line_in_heredoc(t_st *e)
{
	char	*line2;

	ft_start_termcaps();
	e->in_heredoc = TRUE;
	line2 = ft_read_termcaps(e, e->prompt);
	e->in_heredoc = FALSE;
	ft_close_termcaps();
	return (line2);
}

char			*ft_read_in_stdin_for_heredoc(t_st *e, char *str_end)
{
	char	*line;
	char	*line2;

	line = ft_strnew(1);
	ft_get_heredoc_prompt(e);
	while (1)
	{
		line2 = ft_read_line_in_heredoc(e);
		if ((int)line2 == -1)
		{
			free(line);
			return (NULL);
		}
		if (!ft_strcmp(line2, str_end))
		{
			line = ft_strjoinf(line, "\n", 1);
			free(line2);
			break ;
		}
		if (ft_strlen(line) > 0)
			line = ft_strjoinf(line, "\n", 1);
		line = ft_strjoinf(line, line2, 1);
		free(line2);
	}
	return (line);
}

void			ft_read_input(t_st *e)
{
	char	*line;
	char	*prompt;

	prompt = ft_get_prompt(e);
	ft_putstr(prompt);
	free(prompt);
	line = ft_read_in_stdin(e);
	if (!line)
		return ;
	else
		ft_parse_line(e, line);
}
