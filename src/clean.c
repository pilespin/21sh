/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:35:31 by pilespin          #+#    #+#             */
/*   Updated: 2015/04/03 17:00:30 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

char	*ft_clean(char *line)
{
	int		i;
	char	*tmp;

	if (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] <= 31)
				line[i] = ' ';
		}
		i = 0;
		while (line[i] && line[i] <= ' ')
			i++;
		tmp = ft_strsub(line, i, ft_strlen(line) - i);
		if (tmp)
			return (tmp);
	}
	return (NULL);
}

char	*ft_clean_exe(char *line)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (line[i] <= 32 && line[i])
		i++;
	tmp = ft_strsub(line, i, ft_strlen(line) - i);
	i = 0;
	if (tmp)
	{
		while (tmp[i] != ' ' && tmp[i])
			i++;
		tmp2 = ft_strsub(tmp, 0, i);
		free(tmp);
		return (tmp2);
	}
	return (NULL);
}

void	ft_clean_chevron_in_line(char *line, char **tmp2, int i,
													int clean_chevron)
{
	char	*tmp3;
	int		im;

	if (!clean_chevron)
		return ;
	tmp3 = ft_strstr(&line[i + 1], tmp2[0]);
	im = ft_strlen(line) - ft_strlen(tmp3) + ft_strlen(tmp2[0]);
	if (i > 0 && (line[i - 1] == '1' || line[i - 1] == '2'))
		i--;
	while (i >= 0 && line[i] && i < im)
	{
		line[i] = ' ';
		i++;
	}
}
