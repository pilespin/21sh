/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 21:36:52 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_get_quote_prompt(t_st *e, int ret)
{
	free(e->prompt);
	e->prompt = ft_strnew(1);
	if (ret == '\"')
		e->prompt = ft_strjoinf(e->prompt, "d", 1);
	else if (ret == '`')
		e->prompt = ft_strjoinf(e->prompt, "b", 1);
	else if (ret == '{')
		e->prompt = ft_strjoinf(e->prompt, "cursh", 1);
	else if (ret == '(')
		e->prompt = ft_strjoinf(e->prompt, "p", 1);
	else if (ret == '[')
		e->prompt = ft_strjoinf(e->prompt, "c", 1);
	e->prompt = ft_strjoinf(e->prompt, PROMPT_DQUOTE, 1);
}

void	ft_get_heredoc_prompt(t_st *e)
{
	char *tmp;

	tmp = ft_strnew(1);
	tmp = ft_strjoinf(tmp, "heredoc", 1);
	tmp = ft_strjoinf(tmp, PROMPT, 1);
	free(e->prompt);
	e->prompt = tmp;
}

char	*ft_get_prompt(t_st *e)
{
	char	*pwd;
	char	*home;
	char	*tmp;
	char	*tmp2;

	pwd = ft_get_pwd(e);
	home = ft_get_home(e);
	if (home && (tmp = ft_strstr(pwd, home)))
	{
		tmp2 = NULL;
		tmp2 = ft_strsub(pwd, ft_strlen(home),
			ft_strlen(pwd) - ft_strlen(home));
		tmp = ft_strjoin("~", tmp2);
		tmp = ft_strjoinf(tmp, PROMPT, 1);
		free(tmp2);
	}
	else
	{
		tmp = ft_strjoin(pwd, PROMPT);
	}
	free(home);
	free(pwd);
	return (tmp);
}
