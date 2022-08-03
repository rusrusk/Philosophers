# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 11:00:55 by rkultaev          #+#    #+#              #
#    Updated: 2022/08/04 00:01:26 by rkultaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c parsing.c utils.c error.c init.c message.c \
		time.c cycle.c check.c fork.c \
		philo.c 

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread

NC		:= \033[0m
RED 	:= \033[1;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;32m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m


OBJS = $(SRCS:%.c=%.o)

# %.o : %.c
# 		@echo "$(B_GREEN)$(notdir $<) $(NC)"
# 		@$(CC) @(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		@echo "$(BLUE)=============COMPILING===============$(NC)"
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(B_GREEN) COMPILATION OF MANDATORY PART: DONE $(NC)"

all : $(NAME)

clean:
		rm -f $(OBJS)
		@echo "$(RED) Removed $(NC) $(OBJS)"
		
fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

