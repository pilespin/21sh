/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 22:51:58 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/27 22:56:40 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <define.h>

typedef struct			s_history
{
	char				*line;
	struct s_history	*prec;
	struct s_history	*next;
}						t_history;

typedef struct			s_term
{
	char				buf[MAX_READ_TERM];
	char				*res;
	char				*res_tmp;
	char				*tmp;
	char				*tmp2;
	char				*tmp3;
	int					i;
	int					goinhistory;
	int					end_list_inhistory;
	int					imax;
	t_history			*history;
}						t_term;

typedef struct			s_st
{
	char				**env;
	int					fd_0;
	int					fd_1;
	int					fd_2;
	int					fd_file;
	int					signal_exec;
	int					stop_pipe_after_chevron;
	int					random_color_prompt;
	int					color_prompt;
	int					in_heredoc;
	int					pid_fork[MAX_PIPE];
	int					pipefd[MAX_PIPE][2];
	char				*tmp_line;
	char				*tmp_line2;
	int					no_error_exec;
	char				*prompt;
	char				*line;
	char				*str_end_heredoc;
	int					kill_heredoc;
	t_history			*history;
	char				*move_left;
	char				*move_right;
	char				*hide_cursor;
	char				*show_cursor;
	char				*str_copy;
}						t_st;

#endif
