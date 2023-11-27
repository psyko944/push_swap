#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 06:26:53 by mkherbou          #+#    #+#              #
#    Updated: 2022/10/13 12:33:49 by mkherbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

SRCS = srcs/main.c \
srcs/utils.c \
srcs/rotate.c \
srcs/push.c \
srcs/swap.c \
srcs/init.c \
srcs/libft.c  \
srcs/reverse_rotate.c \
srcs/check.c \
srcs/pos.c 

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

CC = cc

RM = rm -f

HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror 
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = ${SRCS:.c=.o}

$(NAME):$(PRINTF) $(OBJS) 
		${CC} $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
		
#$(OBJS) : $(HEADER)


all:	$(NAME)
		@echo "$(GREEN)push swap compiled!$(DEF_COLOR)"

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) ${OBJS}
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

.PHONY: all clean fclean re printf bonus
