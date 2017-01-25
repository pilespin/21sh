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

int			ft_create_pipe(t_st *e, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		if (nb > MAX_PIPE)
		{
			ft_dprintf(2, "%s: Please use less pipe\n", SHNAME);
			return (0);
		}
		if (pipe(e->pipefd[i]) == -1)
		{
			perror("pipe");
			exit(0);
		}
	}
	return (1);
}

static int	ft_check_pipe_error_if_pipe_after_chevron(char **tab_pipe, int i)
{
	char	**tab;

	if ((tab = ft_get_chevron(tab_pipe[i], 0)))
	{
		if (tab_pipe[i + 1])
		{
			ft_freetabchar(tab);
			return (1);
		}
	}
	ft_freetabchar(tab);
	return (0);
}

int			ft_check_pipe_error(char **tab_pipe)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!tab_pipe || !tab_pipe[0] || !tab_pipe[1])
		return (1);
	while (tab_pipe[++i])
	{
		tmp = ft_strtrim(tab_pipe[i]);
		if (ft_strlen(tmp) <= 0)
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		if (ft_check_pipe_error_if_pipe_after_chevron(tab_pipe, i))
			return (1);
	}
	return (0);
}

int			ft_check_if_exit_in_all_command(char **tab)
{
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		tmp = ft_strtrim(tab[i]);
		if (ft_strcmp(tmp, "exit") == 0 || ft_strcmp(tmp, "quit") == 0)
			exit(0);
		free(tmp);
	}
	return (0);
}
