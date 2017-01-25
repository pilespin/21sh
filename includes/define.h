/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:53:20 by pilespin          #+#    #+#             */
/*   Updated: 2016/02/27 21:06:08 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PROMPT "> "
# define PROMPT_DQUOTE "quote}~> "
# define SHNAME "sh"
# define HISTORY_NAME ".sh_history"
# define MAX_PIPE 200
# define MAX_LINE_LENGHT 200
# define MAX_READ_TERM 4

# define KEY__TAB		0x09
# define KEY__RETURN	0x0a
# define KEY__BACKSPACE	0x7f
# define KEY__UP		0x415b1b
# define KEY__DOWN		0x425b1b
# define KEY__RIGHT		0x435b1b
# define KEY__LEFT		0x445b1b
# define KEY__HOME		0x485b1b
# define KEY__END		0x465b1b
# define KEY__PAGE_UP	0x7e355b1b
# define KEY__PAGE_DOWN	0x7e365b1b
# define KEY__CTRL_L	0x0c
# define KEY__CTRL_A	0x01
# define KEY__CTRL_E	0x05
# define KEY__CTRL_Z	0x1a
# define KEY__CTRL_X	0x18
# define KEY__CTRL_Y	0x19
# define KEY__CTRL_P	0x10
# define KEY__CTRL_R	0x12
# define KEY__CTRL_K	0x0b
# define KEY__CTRL_C	0x03
# define KEY__CTRL_D	0x04

# define TRUE 1
# define FALSE 0

# define IN 1
# define OUT 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

#endif
