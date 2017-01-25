/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:44:04 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/19 13:30:33 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

char	*ft_get_cwd(void)
{
	char	*buf;

	buf = (char *)malloc(256);
	getcwd(buf, 255);
	buf[256] = '\0';
	return (buf);
}

char	*ft_get_pwd(t_st *e)
{
	int		i;
	char	*tmp;
	char	*pwd;

	tmp = NULL;
	i = -1;
	while (e->env[++i])
	{
		if (e->env[i][0] == 'P' && e->env[i][1] == 'W' && e->env[i][2] == 'D' &&
			e->env[i][3] == '=')
			tmp = ft_strdup(e->env[i]);
	}
	if (tmp == NULL)
		return (ft_get_cwd());
	pwd = ft_strdup(tmp + 4);
	free(tmp);
	return (pwd);
}

char	*ft_get_oldpwd(t_st *e)
{
	int		i;
	char	*tmp;
	char	*pwd;

	tmp = NULL;
	i = -1;
	while (e->env[++i])
	{
		if (e->env[i][0] == 'O' && e->env[i][1] == 'L' && e->env[i][2] == 'D' &&
			e->env[i][3] == 'P' && e->env[i][4] == 'W' && e->env[i][5] == 'D'
			&& e->env[i][6] == '=')
			tmp = ft_strdup(e->env[i]);
	}
	if (tmp == NULL)
		return (NULL);
	pwd = ft_strdup(tmp + 7);
	free(tmp);
	return (pwd);
}

char	*ft_get_home(t_st *e)
{
	int		i;
	char	*tmp;
	char	*pwd;

	i = -1;
	tmp = NULL;
	while (e->env[++i])
	{
		if (e->env[i][0] == 'H' && e->env[i][1] == 'O' && e->env[i][2] == 'M' &&
			e->env[i][3] == 'E' && e->env[i][4] == '=')
			tmp = ft_strdup(e->env[i]);
	}
	if (tmp == NULL)
		return (NULL);
	pwd = ft_strdup(tmp + 5);
	ft_strdel(&tmp);
	return (pwd);
}

char	**ft_get_path(t_st *e)
{
	int		i;
	char	*all_path;
	char	*tmp;
	char	**path;

	i = -1;
	all_path = NULL;
	while (e->env[++i])
	{
		if (e->env[i][0] == 'P' && e->env[i][1] == 'A' && e->env[i][2] == 'T' &&
			e->env[i][3] == 'H' && e->env[i][4] == '=')
			all_path = ft_strdup(e->env[i]);
	}
	if (all_path == NULL)
		return (NULL);
	tmp = ft_strdup(all_path + 5);
	ft_strdel(&all_path);
	if (ft_strlen(tmp) >= 1)
	{
		path = ft_strsplit(tmp, ':');
		ft_strdel(&tmp);
		return (path);
	}
	ft_strdel(&tmp);
	return (NULL);
}
