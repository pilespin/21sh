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

static char	**ft_get_logic_operator_1(char *line, int i)
{
	char	**tab;

	if (line && line[i] == '|' && line[i + 1] == '|' && line[i + 2] != '|')
	{
		tab = (char**)malloc(sizeof(char *) * 4);
		tab[0] = ft_strdup("||");
		tab[1] = ft_strndup(line, i - 1);
		tab[2] = ft_strsub(line, i + 2, ft_strlen(line) - i - 2);
		tab[3] = NULL;
		return (tab);
	}
	if (line && line[i] == '&' && line[i + 1] == '&' && line[i + 2] != '&')
	{
		tab = (char**)malloc(sizeof(char *) * 4);
		tab[0] = ft_strdup("&&");
		tab[1] = ft_strndup(line, i - 1);
		tab[2] = ft_strsub(line, i + 2, ft_strlen(line) - i - 2);
		tab[3] = NULL;
		return (tab);
	}
	return (NULL);
}

char		**ft_get_logic_operator(char *line)
{
	char	**tab;
	int		i;

	if (ft_strlen(line) < 3)
		return (NULL);
	i = -1;
	while (line[++i] && line[i + 1] && line[i + 2])
	{
		tab = ft_get_logic_operator_1(line, i);
		if (tab)
			return (tab);
	}
	return (NULL);
}
