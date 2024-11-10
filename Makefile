# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:55:38 by tomlimon          #+#    #+#              #
#    Updated: 2024/11/10 23:07:56 by tomlimon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./

SRC_NAME = ft_printchar.c ft_printf.c ft_printpt.c ft_printhex.c ft_printnbr.c ft_printunsigned.c


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OFILES = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "Compilation:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleting:\n\033[33m $(NAME)\033[0m"

re : fclean all

.PHONY: all clean fclean re
