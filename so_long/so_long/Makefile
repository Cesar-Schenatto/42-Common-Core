# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:42:18 by ceaugust          #+#    #+#              #
#    Updated: 2025/02/14 19:21:23 by ceaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc 
CFLAGs = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -fsanitize=undefined
LIBFT_DIR = libft
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR)
SRC = src/main.c 
OBJ = $(SRC:%.c=%.0)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -o $(NAME)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

%.0: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ)
re: fclean all

.PHONY: all clean fclean re
