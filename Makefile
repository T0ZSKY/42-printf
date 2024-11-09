# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:55:38 by tomlimon          #+#    #+#              #
#    Updated: 2024/11/09 04:48:13 by tomlimon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf

NAME = libftprintf.a

# Fichiers source
SRCS = printf.c \
       print_number.c \
       print_pointer.c \
       print_unsigned.c \
       print_char.c \
       print_hex.c

OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)  # Supprime les fichiers objets de printf

fclean: clean
	$(RM) $(NAME)  # Supprime la librairie statique

re: fclean all

obj:
	@echo $(OBJS)

.PHONY: all clean fclean re obj
