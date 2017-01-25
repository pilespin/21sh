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

int		main(int ac, char **av, char **environ)
{
	char *tmp2;
	char **tmp;
	t_st *e;

	e = ft_init_struct(environ);
	tmp2 = ft_get_cwd();
	ft_setenv_new_pwd(e, "", tmp2, tmp2);
	free(tmp2);
	if (!(tmp2 = ft_get_home(e)))
	{
		tmp = ft_addstr_in_tab(e->env, "HOME=/");
		ft_freetabchar(e->env);
		e->env = tmp;
		free(tmp2);
	}
	signal(SIGINT, ft_signal);
	ft_option_c(e, ac, av);
	while (1)
	{
		ft_read_input(e);
	}
	return (0);
}

int		ft_start_builtin(t_st *e, char **tab)
{
	if (ft_strcmp(tab[0], "exit") == 0 || ft_strcmp(tab[0], "quit") == 0)
		ft_exit();
	else if (tab[0] == NULL || ft_strcmp(tab[0], "") == 0)
		return (1);
	else if (ft_strcmp(tab[0], "cd") == 0)
		ft_cd(e, tab);
	else if (ft_strcmp(tab[0], "setenv") == 0)
		ft_setenv(e, tab);
	else if (ft_strcmp(tab[0], "env") == 0)
		ft_env(e, tab);
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		ft_unsetenv(e, tab);
	else if (ft_strncmp(tab[0], "./", 2) == 0)
		ft_execut(e, tab);
	else
		return (0);
	return (1);
}

void	ft_start_command(t_st *e, char **tab)
{
	char **tmp;

	if (!ft_start_builtin(e, tab))
	{
		if (ft_strchr(tab[0], '/'))
			ft_execut_path(e, tab);
		else
		{
			tmp = ft_get_path(e);
			ft_start(e, tab, tmp);
			ft_freetabchar(tmp);
		}
	}
}
