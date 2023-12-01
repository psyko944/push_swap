#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 06:26:53 by mkherbou          #+#    #+#              #
#    Updated: 2023/11/29 12:40:23 by mekherbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
NAME_BONUS = checker

SRCS = srcs/main.c \
srcs/utils.c \
srcs/rotate.c \
srcs/push.c \
srcs/swap.c \
srcs/init.c \
srcs/libft.c  \
srcs/sort.c \
srcs/reverse_rotate.c \
srcs/check.c \
srcs/move.c \
srcs/cost.c \
srcs/ft_split.c \
srcs/pos.c 

SRCS_BONUS = srcs_bonus/get_next_line.c \
			 srcs_bonus/get_next_line_utils.c \
			 srcs_bonus/checker.c \
			 srcs/utils.c \
			 srcs/rotate.c \
			 srcs/push.c \
			 srcs/swap.c \
			 srcs/init.c \
			 srcs/libft.c  \
			 srcs/reverse_rotate.c \
			 srcs/check.c \
			 srcs/ft_split.c \
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
#CFLAGS = -Wall -Wextra -Werror -g3 
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):$(PRINTF) $(OBJS) 
		${CC} $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
		
$(NAME_BONUS):$(PRINTF) $(OBJS_BONUS)
		${CC} $(CFLAGS) $(OBJS_BONUS) $(PRINTF) -o $(NAME_BONUS)

#$(OBJS) : $(HEADER)


all:	$(NAME)
		@echo "$(GREEN)push swap compiled!$(DEF_COLOR)"

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

bonus: $(NAME_BONUS)
	   @echo "$(GREEN)checker compiled!$(DEF_COLOR)"

clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) ${OBJS} ${OBJS_BONUS}
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN)$(NAME) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

.PHONY: all clean fclean re printf bonus
