# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 19:19:22 by ceaugust          #+#    #+#              #
#    Updated: 2024/12/12 07:07:25 by ceaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fsanitize=leak -fno-omit-frame-pointer
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_base.c ft_putuint.c ft_puthexa.c ft_putpointer.c ft_putint.c 
OBJS = $(SRCS:.c=.o)


.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)
re: fclean all
