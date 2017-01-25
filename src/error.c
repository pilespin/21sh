/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:50:20 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/27 19:48:35 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void		ft_command_not_found(char *exe)
{
	if (access(exe, F_OK) != 0)
		ft_dprintf(2, "%s: command not found: %s\n", SHNAME, exe);
}

static void	ft_print_signal_error(int status, char *exe)
{
	if (status == 10)
		ft_dprintf(2, "%s: bus error %s\n", SHNAME, exe);
	else if (status == 11)
		ft_dprintf(2, "%s: segfault %s\n", SHNAME, exe);
	else if (status == 13)
		ft_dprintf(2, "%s: broken pipe %s\n", SHNAME, exe);
	else
		ft_dprintf(2, "error signal -%d %s\n", status, exe);
}

void		ft_wait_and_exit(t_st *e, int ret, char *exe)
{
	int s;

	wait(&s);
	if (s > 2)
		e->signal_exec = s;
	if (WIFSIGNALED(s))
	{
		if (s == 2)
			ft_putstr("^C\n");
		if (s != 2 && !e->no_error_exec)
			ft_print_signal_error(s, exe);
	}
	if (ret == -1)
		ft_exit();
}
