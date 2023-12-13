# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:17:47 by janhan            #+#    #+#              #
#    Updated: 2023/12/12 14:10:51 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex

HEAD =			includes/pipex.h

SRCS =			srcs/pipex.c \
				srcs/ft_pipex_main_process.c \
				srcs/ft_parsing_cmd.c \
				srcs/ft_parsing_cmd_utils.c \
				srcs/ft_get_path.c \
				srcs/ft_free_tab.c \
				srcs/ft_free_info.c \
				srcs/ft_exit_msg.c \
				srcs/ft_putchar.c \
				srcs/ft_putstr.c
LIBFT = libft.a
OBJS	=		$(SRCS:.c=.o)
CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

all : $(NAME)

bonus:
	$(MAKE) -C pipex_bonus
	cp ./pipex_bonus/pipex ./pipex

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/$(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean :
	$(MAKE) -C pipex_bonus clean
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C pipex_bonus fclean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re
