# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 19:19:22 by ceaugust          #+#    #+#              #
#    Updated: 2024/11/20 19:21:14 by ceaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a



LIBFT		= ./libft/libft.a

LIBFTDIR	= ./libft



SRC			= ./src



PRINTF_SRCS	= ft_printf.c ft_printf_hex.c ft_printf_p.c \

				ft_printf_un.c ft_printf_funcs.c



OBJS		= $(PRINTF_SRCS:.c=.o)



CC			= cc 

AR			= ar rcs

RM			= rm -rf 

CFLAGS		= -Wall -Wextra -Werror




all:		$(NAME)



$(NAME):	$(LIBFT) $(OBJS)

				@CP $(LIBFT) $(NAME)

				@$(AR) $(NAME) $(OBJS)



$(LIBFT):	$(LIBFTDIR)

				@$(MAKE) -C $(LIBFTDIR)



%.o: 		$(SRC)/%.c

				@$(CC) $(CFLAGS) -c $< -o $@



clean:

			@$(MAKE) clean -C $(LIBFTDIR)

			@$(RM) $(OBJS)



fclean:		clean

				@$(MAKE) fclean -C $(LIBFTDIR)

				@$(RM) $(NAME)



re:			fclean all
