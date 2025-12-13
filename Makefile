# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 21:16:50 by smakkass          #+#    #+#              #
#    Updated: 2025/12/14 00:03:56 by smakkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_H		=	$(LIBFT_DIR)/libft.h

SRCDIR		=	./src
SRC			=	main.c stack.c error.c stack_utils.c push.c swap.c rotate.c reverse_rotate.c buffer.c sort.c rank.c small_sort.c

INCLUDE_DIR	=	./include
INCLUDE		=	$(INCLUDE_DIR)/push_swap.h

OBJS		=	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -Iinclude -g
RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re