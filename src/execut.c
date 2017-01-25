/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:37:32 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/19 20:07:02 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_execut_path(t_st *e, char **tab_arg)
{
	char	**path;

	path = (char**)malloc(sizeof(char *) * 2);
	path[0] = ft_strdup("/");
	path[1] = NULL;
	ft_start(e, tab_arg, path);
	ft_freetabchar(path);
}

void	ft_execut(t_st *e, char **tab_arg)
{
	char	**path;
	char	*pwd;

	path = (char**)malloc(sizeof(char *) * 2);
	pwd = ft_get_pwd(e);
	path[0] = ft_strjoinf(pwd, "/", 1);
	path[1] = NULL;
	ft_start(e, tab_arg, path);
	ft_freetabchar(path);
}
