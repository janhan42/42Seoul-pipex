# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 21:50:43 by janhan            #+#    #+#              #
#    Updated: 2023/12/12 14:21:35 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex

HEAD =			includes/pipex.h

SRCS =			srcs/ft_child_parent_bonus.c 			\
				srcs/ft_free_info_bonus.c 				\
				srcs/ft_free_tab_bonus.c 				\
				srcs/ft_get_path_bonus.c 				\
				srcs/ft_parsing_cmd_bonus.c 			\
				srcs/ft_parsing_cmd_utils_bonus.c 		\
				srcs/ft_pipex_process_bonus.c 			\
				srcs/ft_putchar_bonus.c 				\
				srcs/ft_putstr_bonus.c 					\
				srcs/get_next_line_bonus.c 				\
				srcs/ft_strcmp_bonus.c					\
				srcs/pipex_bonus.c
LIBFT	= 		libft.a
OBJS	=		$(SRCS:.c=.o)
CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM		=		rm -f

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/$(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean :
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re
