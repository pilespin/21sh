# **************************************************************************** #

#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 14:06:14 by pilespin          #+#    #+#              #
#    Updated: 2016/02/29 20:33:57 by pilespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all compil clean fclean re run leaks incl

NAME	=	21sh

SDIR	=	src/
HDIR	=	includes/
ODIR	=	obj/
FOLDER	=	-I $(HDIR) 

SRCA	=	project.c \
			env.c \
			get.c \
			read.c \
			init.c \
			pipe.c \
			clean.c \
			check.c \
			start.c \
			parse.c \
			error.c \
			insert.c \
			execut.c \
			setenv.c \
			bquote.c \
			history.c \
			chevron.c \
			termcaps.c \
			unsetenv.c \
			get_prompt.c \
			chevron_get.c \
			termcaps_key1.c \
			termcaps_key2.c \
			termcaps_key3.c \
			logic_operator.c \
			chevron_get_right.c \
			chevron_parse_left.c \
			termcaps_binding_core.c \
			get_logic_operator.c \
			termcaps_key_ctrl.c \
			termcaps_init.c \
			pipe_func.c \
			engine.c \
			else.c \
			cd.c \

SRCH	=	project.h \
			struct.h \
			define.h \

SRCO	=	$(SRCA:.c=.o)

CC		=	gcc
LIB		=	-L ./libft/ -lft -lncurses
FLAGS	=	-Wall -Wextra -Werror -pedantic

SRC 	=	$(patsubst %.c, $(SDIR)%.c, $(SRCA))
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(SRCH))
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(SRCA))

all: compil

compil:
	@mkdir -p $(ODIR)
	@echo "\033[32m compiling libft >>> \c \033[0m" 
	@make -C libft
	@echo "\033[32m compiling $(NAME) >>> \c \033[0m" 
	@make $(NAME)

$(NAME): $(OBJ) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) 
	@echo "\033[37m END $(NAME)\033[0m"

$(ODIR)%.o: $(SDIR)%.c $(HDR) libft/libft.a
	@$(CC) -c $< -o $@ $(FLAGS) $(FOLDER)
	@echo "\033[32m ok \033[33m $@\033[0m"

clean:
	@make -C ./libft clean
	@rm -rf $(ODIR)
	@rm -rf the_norm
	@rm -rf the_leaks
	@rm -rf all_incl

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

run:
	@clear
	@make
	@./$(NAME)

leaks:
	@zsh -c "while ((1)) {sleep 1 ; leaks $(NAME) | grep -A 1 Leak > the_leaks ; clear && cat the_leaks}"

norme:
	@zsh -c "while ((1)) {norminette **/*.[ch] | grep -v -B 1 Norme> the_norm && clear && cat the_norm && sleep 10}"

search:
	@zsh -c "grep -n $(s) $(SDIR)**/*.[ch]"

incl:
	@zsh -c "grep -E '(^[a-zA-Z\*\-\_0-9]+\s+[a-zA-Z\*\-\_0-9]+\(.*\))' $(SRC) | cut -d : -f2 | sort > all_incl"
