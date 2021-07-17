# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 02:16:17 by akhalidy          #+#    #+#              #
#    Updated: 2021/07/17 18:41:27 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = libft.a

CC = gcc

SRC  = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	   ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
	   ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_isinteger.c ft_atof.c ft_gnl.c \
	   singly_lst.c singly_lst_clear.c doubly_linked_lst.c circular_db_lst.c \

OBJ  = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)
	@echo libft.a done

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
