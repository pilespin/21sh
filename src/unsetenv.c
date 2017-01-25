/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:42:58 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/26 18:01:31 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

static void	ft_unsetenv_before_setenv_var(t_st *e, char *tmp)
{
	int		j;
	int		k;
	char	**newenv;

	newenv = (char **)malloc(sizeof(char *) * (ft_tablen(e->env) + 2));
	j = -1;
	k = 0;
	while (e->env[++j])
	{
		if (ft_strncmp(e->env[j], tmp, ft_strlen(tmp) - 1) != 0)
			newenv[k++] = e->env[j];
		else
			free(e->env[j]);
	}
	newenv[k] = NULL;
	free(e->env);
	e->env = newenv;
}

void		ft_unsetenv_before_setenv(t_st *e, char **tab_arg)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab_arg[++i])
	{
		tmp = ft_strjoin(tab_arg[i], "=");
		if (ft_check_if_not_exist(e, tab_arg[i]) == -1)
		{
			ft_unsetenv_before_setenv_var(e, tmp);
		}
		free(tmp);
	}
}

static void	ft_unsetenv_var(t_st *e, char **tab_arg, int i)
{
	int		j;
	int		k;
	char	**newenv;
	char	*tmp;

	newenv = (char **)malloc(sizeof(char *) * (ft_tablen(e->env) + 2));
	j = -1;
	k = 0;
	while (e->env[++j])
	{
		tmp = ft_strsub(e->env[j], 0, ft_strlen_char(e->env[j], '='));
		if (ft_strcmp(tab_arg[i], tmp) != 0)
			newenv[k++] = e->env[j];
		else
			free(e->env[j]);
		free(tmp);
	}
	newenv[k] = NULL;
	free(e->env);
	e->env = newenv;
}

void		ft_unsetenv(t_st *e, char **tab_arg)
{
	int		i;

	i = 0;
	while (tab_arg[++i])
	{
		if (ft_check_if_not_exist(e, tab_arg[i]) == -1)
		{
			ft_unsetenv_var(e, tab_arg, i);
		}
		else
			ft_dprintf(2, "%s : %s not exist\n", tab_arg[0], tab_arg[i]);
	}
}
