/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:39:55 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/26 13:10:03 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static void	ft_cd_else(t_st *e, char **tab_arg, int ret)
{
	int		aces;
	char	*pwd;
	char	*cwd;

	aces = 2;
	aces = access(tab_arg[1], F_OK);
	if (aces == 0)
	{
		pwd = ft_get_pwd(e);
		ret = chdir(tab_arg[1]);
		if (ret == -1)
			ft_dprintf(2, "%s : permission denied: %s\n",
				tab_arg[0], tab_arg[1]);
		else
		{
			cwd = ft_get_cwd();
			ft_setenv_new_pwd(e, tab_arg[0], cwd, pwd);
			free(cwd);
		}
		free(pwd);
	}
	else
		ft_dprintf(2, "%s : no such file or directory: %s\n",
			tab_arg[0], tab_arg[1]);
}

void		ft_cd(t_st *e, char **tab_arg)
{
	int		ret;
	char	*home;
	char	*pwd;

	ret = 42;
	if (tab_arg[1] == NULL)
	{
		pwd = ft_get_pwd(e);
		home = ft_get_home(e);
		if (chdir(home) == -1)
			ft_dprintf(2, "%s : home not found\n", tab_arg[0]);
		else
			ft_setenv_new_pwd(e, tab_arg[0], home, pwd);
		free(home);
		free(pwd);
	}
	else if (tab_arg[2] != NULL)
		ft_dprintf(2, "%s: too many arguments\n", tab_arg[0]);
	else
	{
		ft_cd_else(e, tab_arg, ret);
	}
}
