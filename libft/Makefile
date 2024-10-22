# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 17:51:35 by ceaugust          #+#    #+#              #
#    Updated: 2024/10/22 21:27:28 by ceaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
name = libft.a
flags = -Wall -Wextra -Werror
srcs = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
objs = $(srcs:.c=.o)

all: $(name)

$(name): $(objs)
		ar rc $(name) $(objs)

clean: 
		rm -rf $(objs)

fclean: clean
		rm -rf $(name)
re: fclean all 

so:
		$(cc) -nostartfiles -fPIC $(flags) $(srcs)
		gcc -nostartfiles -shared -o libft.so $(objs)
