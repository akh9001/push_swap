# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 13:33:18 by akhalidy          #+#    #+#              #
#    Updated: 2021/08/15 16:33:24 by asmaa-kh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POHONY: all clean fclean re bonus

NAME = push_swap

SRCS =	push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
		ft_fill_stack.c ft_check_error.c ft_max_c_d_lst.c ft_sort_five_num.c \
		ft_min_c_d_lst.c ft_is_sorted.c quick_sort.c ft_main_sort_alg.c\

CFLAGS = -Wall -Wextra -Werror -g

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