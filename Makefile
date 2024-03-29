# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 13:33:18 by akhalidy          #+#    #+#              #
#    Updated: 2021/09/17 19:02:11 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POHONY: all clean fclean re bonus

NAME = push_swap

NAME_BONUS = my_checker

SRCS =	push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
		ft_fill_stack.c ft_check_error.c ft_max_c_d_lst.c ft_sort_five_num.c \
		ft_min_c_d_lst.c ft_is_sorted.c quick_sort.c ft_main_sort_alg.c\
		sort_algo_outils.c sort_algo_outils_2.c \

SRCS_BONUS =	ft_checker.c  ft_read_instructions.c  ft_instruction_bonus.c\
				ft_instruction_2_bonus.c ft_instruction_3_bonus.c \
				ft_swap.c ft_push.c ft_rotate.c ft_reverse.c \
				ft_fill_stack.c ft_check_error.c ft_max_c_d_lst.c ft_sort_five_num.c \
				ft_min_c_d_lst.c ft_is_sorted.c quick_sort.c ft_main_sort_alg.c\
				sort_algo_outils.c sort_algo_outils_2.c\

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(SRCS)
	@make -C libft
	@gcc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)
	@echo push_swap done

clean:
	@make clean -C libft

fclean:
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C libft

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(SRCS_BONUS)
	@make fclean
	@make -C libft
	@gcc $(CFLAGS) $(SRCS_BONUS) libft/libft.a -o $(NAME_BONUS)
	@echo push_swap_bonus done