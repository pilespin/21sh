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

static char		**ft_get_chevron_right_double(char *line, int i,
														int clean_chevron)
{
	char	**tab;
	char	**tmp2;

	if (line[i] == '>' && line[i + 1] == '>')
	{
		tab = (char**)malloc(sizeof(char *) * 5);
		tmp2 = ft_strsplit(&line[i + 2], ' ');
		tab[0] = ft_strdup(tmp2[0]);
		tab[2] = ft_strdup(">>");
		ft_get_chevron_fd_left(tab, line, i);
		tab[4] = NULL;
		ft_clean_chevron_in_line(line, tmp2, i, clean_chevron);
		ft_freetabchar(tmp2);
		return (tab);
	}
	return (NULL);
}

char			**ft_get_chevron_right_core(char *line, int i,
														int clean_chevron)
{
	char	**tab;
	char	**tmp2;

	if (line[i] == '>' && line[i + 1] != '>' && line[i + 1] != '&')
	{
		tab = (char**)malloc(sizeof(char *) * 5);
		tmp2 = ft_strsplit(&line[i + 1], ' ');
		tab[0] = ft_strdup(tmp2[0]);
		tab[2] = ft_strdup(">");
		ft_get_chevron_fd_left(tab, line, i);
		tab[4] = NULL;
		ft_clean_chevron_in_line(line, tmp2, i, clean_chevron);
		ft_freetabchar(tmp2);
		return (tab);
	}
	tab = ft_get_chevron_right_double(line, i, clean_chevron);
	if (tab)
		return (tab);
	return (NULL);
}

char			**ft_get_chevron_right(char *line, int clean_chevron)
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
			tab = ft_get_chevron_right_core(line, i, clean_chevron);
			if (tab)
			{
				ft_freetabchar(tab2);
				tab2 = tab;
			}
		}
	}
	if (tab2)
		return (tab2);
	return (NULL);
}
