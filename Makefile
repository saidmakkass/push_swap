# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 21:16:50 by smakkass          #+#    #+#              #
#    Updated: 2025/12/18 13:21:55 by smakkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap
CHECKER				=	checker

LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a

INCLUDE_DIR			=	./include
PS_INCLUDE			=	$(INCLUDE_DIR)/push_swap.h
CH_INCLUDE			=	$(INCLUDE_DIR)/checker_bonus.h

SRC_DIR				=	./src

PS_DIR				=	$(SRC_DIR)/push_swap
PS_SRC				=	main.c push.c swap.c rotate.c reverse_rotate.c \
						sort.c small_sort.c big_sort.c greedy_insert.c \
						greedy_utils.c stack.c error.c stack_utils.c rank.c

PS_OBJS				=	$(addprefix $(PS_DIR)/, $(PS_SRC:.c=.o))

CH_DIR				=	$(SRC_DIR)/checker

CH_SRC				=	main_bonus.c push_bonus.c reverse_rotate_bonus.c \
						rotate_bonus.c swap_bonus.c checker_bonus.c stack_bonus.c \
						error_bonus.c stack_utils_bonus.c get_next_line_utils_bonus.c \
						get_next_line_bonus.c

CH_OBJS				=	$(addprefix $(CH_DIR)/, $(CH_SRC:.c=.o))

CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -Iinclude -g
RM					=	rm -f

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(PS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(CHECKER): $(CH_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(PS_INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(CH_INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PS_OBJS) $(CH_OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re