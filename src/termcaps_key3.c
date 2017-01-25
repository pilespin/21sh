/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/29 21:17:31 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>
#include <term.h>

void	ft_move_right(t_st *e, t_term *t)
{
	if (ft_strlen(t->res) > 0 && t->imax >= t->i)
	{
		ft_putstr(e->move_right);
		t->i++;
	}
}

void	ft_move_left(t_st *e, t_term *t)
{
	if (t->i > 0)
	{
		ft_putstr(e->move_left);
		t->i--;
	}
}
