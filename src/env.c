/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:39:10 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/19 20:04:57 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_env(t_st *e, char **tab_arg)
{
	char	**tmp;

	tmp = ft_get_path(e);
	if (tab_arg[1] == NULL)
		ft_puttab(e->env);
	else
		ft_start(e, tab_arg, tmp);
	ft_freetabchar(tmp);
}
