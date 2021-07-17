# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 13:33:18 by akhalidy          #+#    #+#              #
#    Updated: 2021/07/17 20:05:38 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POHONY: all clean fclean re bonus

NAME = push_swap

SRCS =	push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
		ft_fill_stack.c ft_check_error.c \

CFLAGS = -Wall -Wextra -Werror

all: $(SRCS)
	@make -C libft
	@gcc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)
	@echo push_swap done

clean:
	@make clean -C libft

fclean:
	@rm -f $(NAME)
	@make fclean -C libft
	
re: fclean all