/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:47:55 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/27 19:48:17 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void		ft_exit(void)
{
	exit(0);
}

static int	ft_check_permission(t_st *e, char **arg, char *tmp, char *exe)
{
	int ret;

	ret = 0;
	if (ft_strncmp(exe, "./", 2) == 0)
	{
		if (ft_check_acces(tmp, exe) == -1)
			exit(0);
	}
	if (access(tmp, F_OK) == 0 && access(tmp, X_OK) != 0)
	{
		ft_dprintf(2, "permission denied: %s\n", exe);
		exit(0);
	}
	else
	{
		ret = 2;
		ret = execve(tmp, arg, e->env);
	}
	return (ret);
}

static char	*ft_join_path_and_exe(char **path, char *exe, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strjoin(path[i], "/");
	tmp = ft_strjoin(tmp2, exe);
	ft_strdel(&tmp2);
	return (tmp);
}

void		ft_start(t_st *e, char **arg, char **path)
{
	char	*tmp;
	int		i;
	int		ret;

	i = -1;
	if (path)
	{
		while (path[++i])
		{
			tmp = ft_join_path_and_exe(path, arg[0], i);
			if (!access(tmp, F_OK))
			{
				if (ft_fork() > 0)
				{
					ft_strdel(&tmp);
					ft_wait_and_exit(e, ret, arg[0]);
					return ;
				}
				else
					ret = ft_check_permission(e, arg, tmp, arg[0]);
			}
			ft_strdel(&tmp);
		}
	}
	ft_command_not_found(arg[0]);
}
