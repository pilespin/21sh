/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:46:45 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/26 13:28:53 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

int			ft_check_if_not_exist(t_st *e, char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (str[i++] != '=' && str[i])
		;
	tmp = ft_strndup(str, i);
	i = -1;
	while (e->env[++i])
	{
		tmp2 = ft_strsub(e->env[i], 0, ft_strlen_char(e->env[i], '='));
		if (ft_strcmp(tmp, tmp2) == 0)
		{
			free(tmp2);
			free(tmp);
			return (-1);
		}
		free(tmp2);
	}
	free(tmp);
	return (1);
}

int			ft_check_acces(char *tmp, char *exe)
{
	int		aces;

	aces = 2;
	aces = access(tmp, F_OK);
	if (aces == -1)
		ft_dprintf(2, "%s : file not found: %s\n", SHNAME, exe + 2);
	else
	{
		aces = 2;
		aces = access(tmp, X_OK);
		if (aces == -1)
			ft_dprintf(2, "%s : permission denied: %s\n", SHNAME, exe + 2);
	}
	return (aces);
}

static int	ft_check_else(char *line)
{
	char	*dquote;
	int		i;

	dquote = ft_strdup("(){}[]\0");
	i = 0;
	while (dquote[i])
	{
		if (ft_count_char(line, dquote[i]) !=
			ft_count_char(line, dquote[i + 1]))
		{
			free(dquote);
			return (dquote[i]);
		}
		i += 2;
	}
	free(dquote);
	return (0);
}

int			ft_check_dquote_or_else(char *line)
{
	char	*dquote;
	int		i;
	int		ret;

	dquote = ft_strdup("\"\'`\0");
	i = -1;
	while (dquote[++i])
	{
		if (ft_isimpair(ft_count_char(line, dquote[i])))
		{
			free(dquote);
			return (dquote[i]);
		}
	}
	if ((ret = ft_check_else(line)))
		return (ret);
	free(dquote);
	return (0);
}
