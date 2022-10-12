#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 06:26:53 by mkherbou          #+#    #+#              #
#    Updated: 2022/10/12 16:17:58 by mkherbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

SRCS = srcs/main.c \
srcs/utils.c \
srcs/sort.c \
srcs/rotate.c \
srcs/push.c \
srcs/swap.c \
srcs/init.c \
srcs/libft.c  \
srcs/reverse_rotate.c \

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = gcc

RM = rm -f

HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror 

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS) 
		${CC} $(CFLAGS) $(OBJS) -o $(NAME)
		
#$(OBJS) : $(HEADER)


all:	$(NAME)
		@echo "$(GREEN)push swap compiled!$(DEF_COLOR)"

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY: all clean fclean re minilibx libft printf bonus
