/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 18:10:32 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static	int		ft_parse_left_one_chevron(t_st *e, char **tmp, char *name)
{
	if (ft_strcmp(tmp[2], "<") == 0)
	{
		e->fd_file = open(name, O_RDONLY);
		if (e->fd_file != -1)
		{
			close(0);
			dup(e->fd_file);
		}
		else
		{
			ft_dprintf(2, "%s: error open: %s\n", SHNAME, name);
			return (-1);
		}
	}
	return (0);
}

static	void	ft_fork_and_put_in_pipe(t_st *e)
{
	if ((e->pid_fork[1] = ft_fork()) == 0)
	{
		close(e->pipefd[0][OUT]);
		ft_putstr_fd(e->tmp_line2, e->pipefd[0][IN]);
		exit(0);
	}
}

static int		ft_parse_left_two_chevron(t_st *e, char **tmp, char **right)
{
	if (ft_strcmp(tmp[2], "<<") == 0)
	{
		e->tmp_line2 = ft_read_in_stdin_for_heredoc(e, e->str_end_heredoc);
		if (!e->tmp_line2)
			return (-1);
		ft_create_pipe(e, 1);
		ft_fork_and_put_in_pipe(e);
		if (right)
			ft_parse_right_chevron(e, right);
		close(e->pipefd[0][IN]);
		dup2(e->pipefd[0][OUT], STDIN);
		free(e->tmp_line);
		e->tmp_line = ft_strdup(tmp[1]);
	}
	else
	{
		free(e->tmp_line);
		e->tmp_line = ft_strdup(tmp[1]);
	}
	return (0);
}

int				ft_parse_left_chevron(t_st *e, char **tmp, char **right)
{
	char	**tmp3;

	if (ft_strcmp(tmp[2], "<") == 0 || ft_strcmp(tmp[2], "<<") == 0)
	{
		if (ft_strlen(tmp[1]) <= 0)
		{
			ft_dprintf(2, "%s: parse error near: %s\n", SHNAME, tmp[2]);
			return (-1);
		}
		tmp3 = ft_strsplit(tmp[0], ' ');
		e->str_end_heredoc = ft_strtrim(tmp3[0]);
		ft_freetabchar(tmp3);
		if (ft_parse_left_one_chevron(e, tmp, e->str_end_heredoc) == -1)
		{
			free(e->str_end_heredoc);
			return (-1);
		}
		if (ft_parse_left_two_chevron(e, tmp, right) == -1)
		{
			free(e->str_end_heredoc);
			return (-1);
		}
		free(e->str_end_heredoc);
	}
	return (0);
}
