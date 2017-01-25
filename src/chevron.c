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

static	void	ft_get_flux_redirect_right(char **tab, char *line, int i)
{
	if (i > 1 && line[i] && line[i + 1] && line[i + 2] &&
		line[i + 1] == '&' && (line[i + 2] == '1' ||
			line[i + 2] == '2' || line[i + 2] == '-'))
	{
		tab[4] = ft_strndup(&line[i + 2], 1);
		line[i] = ' ';
		line[i - 1] = ' ';
		line[i + 1] = ' ';
		line[i + 2] = ' ';
	}
	else
		tab[4] = NULL;
}

char			**ft_get_flux_redirect(char *line)
{
	int		i;
	char	**tab;
	char	**tab2;

	tab2 = NULL;
	i = -1;
	while (line[++i])
	{
		if (!line[i + 1] && !line[i + 2] && i > 0)
			break ;
		if (line[i] == '>' && line[i + 1] == '&')
		{
			tab = malloc(sizeof(char *) * 6);
			tab[0] = ft_strsub(line, i + 1, ft_strlen(line) - i - 1);
			tab[2] = ft_strdup(">");
			ft_get_chevron_fd_left(tab, line, i);
			ft_get_flux_redirect_right(tab, line, i);
			tab[5] = NULL;
			ft_freetabchar(tab2);
			tab2 = tab;
		}
	}
	if (tab2)
		return (tab2);
	return (NULL);
}

void			ft_parse_right_chevron(t_st *e, char **tmp)
{
	char	*name;

	if (ft_strcmp(tmp[2], ">") == 0 || ft_strcmp(tmp[2], ">>") == 0)
	{
		name = ft_strtrim(tmp[0]);
		e->fd_file = open(name, O_RDWR);
		if (e->fd_file == -1)
			e->fd_file = open(name, O_RDWR | O_CREAT, 0600);
		else
		{
			if (ft_strcmp(tmp[2], ">") == 0)
				e->fd_file = open(name, O_RDWR | O_TRUNC, 0600);
			else if (ft_strcmp(tmp[2], ">>") == 0)
				e->fd_file = open(name, O_RDWR | O_APPEND, 0600);
		}
		free(name);
		if (tmp && tmp[3][0])
		{
			dup2(e->fd_file, ft_atoi(tmp[3]));
		}
		else
		{
			dup2(e->fd_file, 1);
		}
	}
}
