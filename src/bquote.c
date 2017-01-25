/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/26 13:30:34 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static int	ft_bquote_get_position_start(char *line)
{
	int	i;

	if (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == '`')
				return (i);
		}
	}
	return (-1);
}

static int	ft_bquote_get_position_end(char *line)
{
	int	i;
	int pass;

	if (line)
	{
		pass = 0;
		i = -1;
		while (line[++i])
		{
			if (line[i] == '`')
			{
				pass++;
				if (pass == 2)
					return (i);
			}
		}
	}
	return (-1);
}

static void	ft_fork_and_execut_command(t_st *e, char *line)
{
	if (ft_fork() == 0)
	{
		close(STDOUT);
		dup(e->pipefd[0][1]);
		close(e->pipefd[0][0]);
		ft_parse_line(e, line);
		close(e->pipefd[0][1]);
		exit(0);
	}
}

static char	*ft_read_and_concat_in_pipe(t_st *e)
{
	char	*line2;
	char	*line4;

	line4 = ft_strnew(1);
	while ((line2 = ft_getline(e->pipefd[0][0])))
	{
		line4 = ft_strjoinf(line4, " ", 1);
		line4 = ft_strjoinf(line4, line2, 1);
		free(line2);
	}
	close(e->pipefd[0][0]);
	return (line4);
}

char		*ft_parse_bquote(t_st *e, char *line)
{
	char	*tmp;
	int		start;
	int		end;
	char	*line2;
	char	*line4;

	if (!line)
		return (NULL);
	if (ft_count_char(line, '`') >= 2)
	{
		end = ft_bquote_get_position_end(line);
		start = ft_bquote_get_position_start(line);
		tmp = ft_strsub(line, start + 1, end - start - 1);
		ft_create_pipe(e, 1);
		ft_fork_and_execut_command(e, tmp);
		close(e->pipefd[0][1]);
		wait(NULL);
		line4 = ft_read_and_concat_in_pipe(e);
		line2 = ft_insert_str_in_line(line, line4, start, end);
		free(line4);
		free(tmp);
		free(line);
		return (line2);
	}
	return (NULL);
}
