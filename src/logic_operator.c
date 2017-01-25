/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 20:33:16 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static void	ft_select_pipe_or_not(t_st *e, char *line)
{
	if (ft_strchr(line, '|'))
		ft_parse_pipe(e, line);
	else
		ft_split_arg(e, line);
}

static int	ft_parse_logic_operator_et(t_st *e, char **tab_line,
	char **tab, int i)
{
	if (!ft_strcmp(tab[0], "&&"))
	{
		free(tab_line[i]);
		tab_line[i] = ft_strdup(tab[1]);
		e->signal_exec = 0;
		ft_select_pipe_or_not(e, tab_line[i]);
		if (e->signal_exec == 0)
		{
			free(tab_line[i]);
			tab_line[i] = ft_strdup(tab[2]);
			i--;
		}
		else
			return (-10);
	}
	return (i);
}

static int	ft_parse_logic_operator_ou(t_st *e, char **tab_line,
	char **tab, int i)
{
	if (!ft_strcmp(tab[0], "||"))
	{
		free(tab_line[i]);
		tab_line[i] = ft_strdup(tab[1]);
		e->signal_exec = 0;
		ft_select_pipe_or_not(e, tab_line[i]);
		if (e->signal_exec > 2)
		{
			free(tab_line[i]);
			tab_line[i] = ft_strdup(tab[2]);
			i--;
		}
	}
	return (i);
}

void		ft_parse_logic_operator(t_st *e, char **tab_line)
{
	int		i;
	char	**tab;

	if (tab_line)
	{
		i = -1;
		while (tab_line[++i])
		{
			if ((tab = ft_get_logic_operator(tab_line[i])))
			{
				i = ft_parse_logic_operator_ou(e, tab_line, tab, i);
				i = ft_parse_logic_operator_et(e, tab_line, tab, i);
				if (i == -10)
				{
					ft_freetabchar(tab);
					ft_restore_fd(e);
					return ;
				}
				ft_freetabchar(tab);
			}
			else
				ft_select_pipe_or_not(e, tab_line[i]);
			ft_restore_fd(e);
		}
	}
}
