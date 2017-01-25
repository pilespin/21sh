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

void	ft_signal(int ret)
{
	(void)ret;
}

void	ft_option_c(t_st *e, int ac, char **av)
{
	if (ac != 1)
	{
		if (ac == 3 && ft_strcmp(av[1], "-c") == 0 && ft_strlen(av[2]) > 0)
			ft_parse_line(e, ft_strdup(av[2]));
		else
			ft_dprintf(2, "%s: Usage -c \"command line\"\n", SHNAME);
		exit(0);
	}
}

void	ft_restore_fd(t_st *e)
{
	close(0);
	dup(e->fd_0);
	close(1);
	dup(e->fd_1);
	close(2);
	dup(e->fd_2);
}

pid_t	ft_fork(void)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(0);
	}
	return (cpid);
}
