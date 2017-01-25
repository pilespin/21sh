/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:33:39 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/26 13:23:13 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static void	ft_insert_special_caracter_olp_pwd(t_st *e, char **tab_arg)
{
	int		i;
	int		j;
	char	*end;
	char	*tmp;

	i = 0;
	if (tab_arg)
	{
		while (tab_arg[++i])
		{
			j = 0;
			if (tab_arg[i][j] == '-')
			{
				tmp = ft_get_oldpwd(e);
				if (tmp)
				{
					end = ft_strsub(tab_arg[i], 1, ft_strlen(tab_arg[i]) - 1);
					free(tab_arg[i]);
					tab_arg[i] = ft_strjoinf(tmp, "/", 1);
					tab_arg[i] = ft_strjoinf(tab_arg[i], end, 1);
					free(end);
				}
			}
		}
	}
}

static void	ft_insert_special_caracter_tilde(t_st *e, char **tab_arg)
{
	int		i;
	char	*end;
	char	*tmp;

	i = 0;
	while (tab_arg[++i])
	{
		if (tab_arg[i][0] == '~')
		{
			tmp = ft_get_home(e);
			end = ft_strsub(tab_arg[i], 1, ft_strlen(tab_arg[i]) - 1);
			free(tab_arg[i]);
			tab_arg[i] = ft_strjoin(tmp, end);
			free(end);
			free(tmp);
		}
	}
}

void		ft_insert_special_caracter(t_st *e, char **tab_arg)
{
	if (!tab_arg)
		return ;
	if (ft_strcmp(tab_arg[0], "cd") == 0)
		ft_insert_special_caracter_olp_pwd(e, tab_arg);
	ft_insert_special_caracter_tilde(e, tab_arg);
}

char		*ft_insert_str_in_line(char *line, char *add, int start, int end)
{
	char	*tmp1;
	char	*tmp2;
	char	*line3;

	tmp1 = ft_strsub(line, 0, start);
	tmp2 = ft_strsub(line, end + 1, ft_strlen(line));
	line3 = ft_strjoin(tmp1, add);
	line3 = ft_strjoinf(line3, tmp2, 1);
	free(tmp1);
	free(tmp2);
	return (line3);
}

char		*ft_delete_str_in_line(char *line, int start, int end)
{
	char	*tmp1;
	char	*tmp2;
	char	*line3;

	tmp1 = ft_strsub(line, 0, start);
	tmp2 = ft_strsub(line, end, ft_strlen(line));
	line3 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (line3);
}
