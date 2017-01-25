/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/27 22:35:23 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static	void	ft_close_pipe(t_st *e, int nb)
{
	if (nb >= 1)
	{
		close(e->pipefd[nb - 1][OUT]);
		close(e->pipefd[nb - 1][IN]);
	}
}

static	void	ft_fork_pipe(t_st *e, char **tab_pipe, int nb_pipe, int j)
{
	int		nb;

	nb = 0;
	while (nb < nb_pipe)
	{
		if (ft_fork() == 0)
		{
			if (nb < nb_pipe - 1)
			{
				close(e->pipefd[nb][OUT]);
				dup2(e->pipefd[nb][IN], STDOUT);
			}
			if (nb >= 1)
			{
				close(e->pipefd[nb - 1][IN]);
				dup2(e->pipefd[nb - 1][OUT], STDIN);
			}
			ft_split_arg(e, tab_pipe[j]);
			exit(0);
		}
		ft_close_pipe(e, nb);
		nb++;
		j++;
	}
}

static	void	ft_wait_fork_for_pipe(int nb_pipe)
{
	int		nb;

	nb = -1;
	while (++nb < nb_pipe)
		wait(NULL);
}

static	int		ft_split_and_fork_pipe(t_st *e, char **tab_pipe, char *line)
{
	int		j;
	int		nb_pipe;
	int		nb_pipe2;

	nb_pipe = 0;
	j = -1;
	if (tab_pipe)
	{
		if (tab_pipe[++j] && tab_pipe[j + 1])
		{
			nb_pipe = ft_tablen(tab_pipe);
			nb_pipe2 = ft_count_char(line, '|');
			if (ft_create_pipe(e, nb_pipe + 2))
			{
				e->no_error_exec = 1;
				ft_fork_pipe(e, tab_pipe, nb_pipe, j);
				ft_wait_fork_for_pipe(nb_pipe);
				e->no_error_exec = 0;
			}
		}
	}
	return (nb_pipe);
}

void			ft_parse_pipe(t_st *e, char *line)
{
	char	**tab_pipe;
	char	*tmp;
	int		nb_pipe;

	tmp = ft_strtrim(line);
	tab_pipe = ft_strsplit(tmp, '|');
	free(tmp);
	if (ft_check_pipe_error(tab_pipe))
	{
		ft_freetabchar(tab_pipe);
		ft_dprintf(2, "%s: parse error near pipe\n", SHNAME);
		return ;
	}
	ft_check_if_exit_in_all_command(tab_pipe);
	nb_pipe = ft_split_and_fork_pipe(e, tab_pipe, line);
	ft_wait_fork_for_pipe(nb_pipe);
	ft_freetabchar(tab_pipe);
}
