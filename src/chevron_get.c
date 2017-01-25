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

void			ft_get_chevron_fd_left(char **tab, char *line, int i)
{
	if (line[i - 1] == '1' || line[i - 1] == '2')
	{
		tab[1] = ft_strsub(line, 0, i - 1);
		tab[3] = ft_strndup(&line[i - 1], 1);
	}
	else
	{
		tab[1] = ft_strsub(line, 0, i);
		tab[3] = ft_strnew(1);
	}
}

static	char	**ft_get_chevron_left_core(char *line, int i, int clean_chevron)
{
	char	**tab;
	char	**tmp2;

	if (line[i] == '<' && line[i + 1] != '<')
	{
		tab = (char**)malloc(sizeof(char *) * 4);
		tmp2 = ft_strsplit(&line[i + 1], ' ');
		tab[0] = ft_strsub(line, i + 1, ft_strlen(line) - i - 1);
		tab[1] = ft_strsub(line, 0, i);
		tab[2] = ft_strdup("<");
		tab[3] = NULL;
		ft_clean_chevron_in_line(line, tmp2, i, clean_chevron);
		ft_freetabchar(tmp2);
		return (tab);
	}
	else if (line[i] == '<' && line[i + 1] == '<')
	{
		tab = (char**)malloc(sizeof(char *) * 4);
		tab[0] = ft_strsub(line, i + 2, ft_strlen(line) - i - 2);
		tab[1] = ft_strsub(line, 0, i);
		tab[2] = ft_strdup("<<");
		tab[3] = NULL;
		return (tab);
	}
	return (NULL);
}

char			**ft_get_chevron_left(char *line, int clean_chevron)
{
	int		i;
	char	**tab;
	char	**tab2;

	tab2 = NULL;
	i = -1;
	while (line[++i])
	{
		if (line[i] && line[i + 1])
		{
			tab = ft_get_chevron_left_core(line, i, clean_chevron);
			if (tab)
			{
				ft_freetabchar(tab2);
				tab2 = tab;
				if (ft_strcmp(tab2[2], "<<") == 0)
					return (tab2);
			}
		}
	}
	if (tab2)
		return (tab2);
	return (NULL);
}

char			**ft_get_chevron(char *line, int clean_chevron)
{
	int		i;
	char	**tab;
	char	**tab2;

	tab2 = NULL;
	i = -1;
	while (line[++i])
	{
		if (line[i] && line[i + 1] && line[i + 2])
		{
			tab = ft_get_chevron_right_core(line, i, clean_chevron);
			if (!tab)
				tab = ft_get_chevron_left_core(line, i, clean_chevron);
			if (tab)
			{
				ft_freetabchar(tab2);
				tab2 = tab;
				if (ft_strcmp(tab2[2], "<<") == 0)
					return (tab2);
			}
		}
	}
	if (tab2)
		return (tab2);
	return (NULL);
}
