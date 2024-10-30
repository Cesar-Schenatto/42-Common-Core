# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 17:51:35 by ceaugust          #+#    #+#              #
#    Updated: 2024/10/30 19:26:45 by ceaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
name = libft.a
flags = -Wall -Wextra -Werror
srcs = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_calloc.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c  
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
