# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 16:14:45 by vdaemoni          #+#    #+#              #
#    Updated: 2020/08/27 17:14:40 by vdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRC		=	src/main.c \
			src/blt.c \
			src/builtins/cmd_cd.c \
			src/builtins/cmd_echo.c \
			src/builtins/cmd_env.c \
			src/builtins/cmd_exit.c \
			src/builtins/cmd_help.c \
			src/builtins/cmd_pwd.c \
			src/builtins/cmd_setenv.c \
			src/builtins/cmd_unsetenv.c \
			src/tricky.c \
			src/execute.c \
			src/minishell.c \
			src/helpers/ft_bzero.c \
			src/helpers/ft_error.c \
			src/helpers/ft_find_env.c \
			src/helpers/ft_memalloc.c \
			src/helpers/ft_memset.c \
			src/helpers/ft_putchar.c \
			src/helpers/ft_putendl.c \
			src/helpers/ft_putstr.c \
			src/helpers/ft_strcat.c \
			src/helpers/ft_strchr.c \
			src/helpers/ft_strclr.c \
			src/helpers/ft_strcmp.c \
			src/helpers/ft_strcpy.c \
			src/helpers/ft_strdup.c \
			src/helpers/ft_strjoin.c \
			src/helpers/ft_strlen.c \
			src/helpers/ft_strncat.c \
			src/helpers/ft_strncmp.c \
			src/helpers/ft_strncpy.c \
			src/helpers/ft_strnew.c \
			src/helpers/ft_strrchr.c \
			src/helpers/ft_strsub.c \
			src/helpers/ft_strtok.c \
			src/helpers/ft_tabfree.c \
			src/helpers/ft_tablen.c \
			src/helpers/get_next_line.c

INC		=	inc/

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(INC)
OBJ		=	$(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	@printf "minishell: Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "minishell: Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "minishell: Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@printf "minishell: Removed object files\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "minishell: Removed minishell binary\n"
	
re: fclean all

.PHONY: all clean fclean re
