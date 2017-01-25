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

static void	ft_parse_flux_redirect(char **flux)
{
	if (flux)
	{
		if (flux && flux[4] && flux[4][0])
		{
			if (flux[4][0] == '-')
				close(ft_atoi(flux[3]));
			else
				dup2(ft_atoi(flux[4]), ft_atoi(flux[3]));
		}
	}
}

static void	ft_parse_chevron_end(t_st *e, char **tmp)
{
	if (tmp)
	{
		if (ft_strcmp(tmp[2], ">") == 0 || ft_strcmp(tmp[2], ">>") == 0 ||
			ft_strcmp(tmp[2], "<") == 0)
		{
			close(e->fd_file);
		}
		if (ft_strcmp(tmp[2], "<<") == 0)
		{
			wait(NULL);
			free(e->tmp_line2);
		}
	}
}

static void	ft_parse_chevron(t_st *e)
{
	char	**tab;

	tab = ft_strsplit(e->tmp_line, ' ');
	free(e->tmp_line);
	if (tab)
	{
		ft_insert_special_caracter(e, tab);
		ft_start_command(e, tab);
	}
	ft_freetabchar(tab);
}

static int	ft_parse_chevron_select(t_st *e, char **left, char **right)
{
	if (right)
	{
		if (!left || (left && ft_strcmp(left[2], "<<")))
			ft_parse_right_chevron(e, right);
	}
	if (left && ft_parse_left_chevron(e, left, right) == -1)
	{
		ft_freetabchar(left);
		ft_freetabchar(right);
		free(e->tmp_line);
		return (-1);
	}
	return (0);
}

void		ft_split_arg(t_st *e, char *line)
{
	char	**left;
	char	**right;
	char	**flux;

	e->tmp_line = ft_strtrim(line);
	if (ft_strlen(e->tmp_line) <= 0)
	{
		free(e->tmp_line);
		return ;
	}
	right = ft_get_chevron_right(e->tmp_line, 1);
	left = ft_get_chevron_left(e->tmp_line, 1);
	if (ft_parse_chevron_select(e, left, right) == -1)
		return ;
	flux = ft_get_flux_redirect(e->tmp_line);
	ft_parse_flux_redirect(flux);
	ft_parse_chevron(e);
	ft_parse_chevron_end(e, right);
	ft_parse_chevron_end(e, left);
	ft_freetabchar(left);
	ft_freetabchar(right);
	ft_freetabchar(flux);
}
