/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:40:59 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/19 20:25:48 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void		ft_setenv_new_pwd(t_st *e, char *exe, char *path, char *oldpwd)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup(exe);
	tab[1] = ft_strjoin("PWD=", path);
	tab[2] = ft_strjoin("OLDPWD=", oldpwd);
	tab[3] = NULL;
	ft_setenv(e, tab);
	ft_freetabchar(tab);
}

static char	**ft_keep_just_name_of_var(char **tab_arg)
{
	int		i;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_tablen(tab_arg) + 2));
	i = 0;
	tab[0] = ft_strdup(tab_arg[i]);
	while (tab_arg[++i])
		tab[i] = ft_strsub(tab_arg[i], 0, ft_strlen_char(tab_arg[i], '='));
	tab[i] = NULL;
	return (tab);
}

void		ft_setenv(t_st *e, char **tab_arg)
{
	int		i;
	char	**tmp;
	char	**tmp2;

	if (tab_arg[1] == NULL)
	{
		ft_dprintf(2, "%s: too fiew arguments\n", tab_arg[0]);
	}
	i = 0;
	tmp2 = ft_keep_just_name_of_var(tab_arg);
	ft_unsetenv_before_setenv(e, tmp2);
	ft_freetabchar(tmp2);
	while (tab_arg[++i])
	{
		tmp = ft_addstr_in_tab(e->env, tab_arg[i]);
		ft_freetabchar(e->env);
		e->env = tmp;
	}
}

char		**ft_addstr_in_tab(char **tab, char *str)
{
	char	**newtab;
	int		i;

	newtab = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 2));
	i = -1;
	while (tab[++i])
	{
		newtab[i] = ft_strdup(tab[i]);
	}
	newtab[i++] = ft_strdup(str);
	newtab[i] = NULL;
	return (newtab);
}
