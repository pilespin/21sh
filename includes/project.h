/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:53:20 by pilespin          #+#    #+#             */
/*   Updated: 2016/03/12 14:34:27 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/includes/libft.h"
# include <struct.h>
# include <define.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <curses.h>

# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>

char	**ft_get_chevron(char *line, int clean_chevron);
char	**ft_get_chevron_left(char *line, int clean_chevron);
char	**ft_get_chevron_right(char *line, int clean_chevron);
char	**ft_get_chevron_right_core(char *line, int i, int clean_chevron);
char	**ft_get_flux_redirect(char *line);
char	*ft_read_in_stdin(t_st *e);
char	*ft_read_in_stdin_for_heredoc(t_st *e, char *str_end);
char	**ft_addstr_in_tab(char **tab, char *str);
char	**ft_get_logic_operator(char *line);
char	*ft_delete_str_in_line(char *line, int start, int end);
char	*ft_insert_str_in_line(char *line, char *add, int start, int end);
char	*ft_parse_bquote(t_st *e, char *line);
char	*ft_read_termcaps(t_st *e, char *prompt);
char	**ft_get_path(t_st *e);
char	*ft_clean(char *line);
char	*ft_clean_exe(char *line);
char	*ft_get_cwd(void);
char	*ft_get_home(t_st *e);
char	*ft_get_oldpwd(t_st *e);
char	*ft_get_prompt(t_st *e);
char	*ft_get_pwd(t_st *e);
char	*ft_key_return(t_term *t);
int		ft_parse_left_chevron(t_st *e, char **tmp, char **right);
int		ft_check_acces(char *tmp, char *exe);
int		ft_check_dquote_or_else(char *line);
int		ft_check_if_not_exist(t_st *e, char *str);
int		ft_check_if_exit_in_all_command(char **tab);
int		ft_check_pipe_error(char **tab_pipe);
int		ft_close_termcaps(void);
int		ft_create_pipe(t_st *e, int nb);
int		ft_key_backspace(t_st *e, t_term *t);
int		ft_key_copy_and_paste(t_st *e, t_term *t);
int		ft_key_ctrl_c(t_st *e, t_term *t);
int		ft_key_ctrl_d(t_term *t);
int		ft_key_ctrl_l_k(t_st *e, t_term *t);
int		ft_key_ctrl_x(t_st *e, t_term *t);
int		ft_key_ctrl_z(t_st *e, t_term *t);
int		ft_key_down_history(t_st *e, t_term *t);
int		ft_key_home_and_end(t_st *e, t_term *t);
int		ft_key_left_right(t_st *e, t_term *t);
int		ft_key_page_up_and_down(t_st *e, t_term *t);
int		ft_key_tabulation(t_st *e, t_term *t);
int		ft_key_up_history(t_st *e, t_term *t);
int		ft_start_builtin(t_st *e, char **tab);
int		ft_start_termcaps(void);
int		main(int ac, char **av, char **environ);
pid_t	ft_fork(void);
t_st	*ft_init_struct(char **environ);
t_term	*ft_init_struct_term(t_st *e, char *prompt);
void	ft_add_in_history(t_st *e, char *line);
void	ft_get_chevron_fd_left(char **tab, char *line, int i);
void	ft_parse_pipe(t_st *e, char *line);
void	ft_parse_right_chevron(t_st *e, char **tmp);
void	ft_read_input(t_st *e);
void	ft_read_line(t_term *t);
void	ft_cd(t_st *e, char **tab_arg);
void	ft_command_not_found(char *exe);
void	ft_exit(void);
void	ft_insert_special_caracter(t_st *e, char **tab_arg);
void	ft_parse_line(t_st *e, char *line);
void	ft_parse_logic_operator(t_st *e, char **tab_line);
void	ft_setenv(t_st *e, char **tab_arg);
void	ft_setenv_new_pwd(t_st *e, char *exe, char *path, char *oldpwd);
void	ft_split_arg(t_st *e, char *line);
void	ft_start(t_st *e, char **arg, char **path);
void	ft_unsetenv(t_st *e, char **tab_arg);
void	ft_unsetenv_before_setenv(t_st *e, char **tab_arg);
void	ft_wait_and_exit(t_st *e, int ret, char *exe);
void	ft_add_str_in_str(t_st *e, t_term *t, char *str);
void	ft_clean_chevron_in_line(char *line, char **tmp2, int i,
														int clean_chevron);
void	ft_clear_line(t_st *e, t_term *t);
void	ft_env(t_st *e, char **tab_arg);
void	ft_execut(t_st *e, char **tab_arg);
void	ft_execut_path(t_st *e, char **tab_arg);
void	ft_get_heredoc_prompt(t_st *e);
void	ft_get_quote_prompt(t_st *e, int ret);
void	ft_move_left(t_st *e, t_term *t);
void	ft_move_right(t_st *e, t_term *t);
void	ft_option_c(t_st *e, int ac, char **av);
void	ft_put_line(t_term *t, char *line);
void	ft_putctrl(char ctrl);
void	ft_refresh_line(t_st *e, t_term *t, int stayright);
void	ft_restore_fd(t_st *e);
void	ft_signal(int ret);
void	ft_start_command(t_st *e, char **tab);

#endif
