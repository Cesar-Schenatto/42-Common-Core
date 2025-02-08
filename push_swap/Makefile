CC := cc

CFLAGS := -g -Wall -Werror -Wextra



# Directories

SRC_DIR := src

OBJ_DIR := obj

INC_DIR := include



# Source files (only .c files)

SRC_FILES := main.c parse.c checkstack.c push_swap.c reverse.c sort_four.c sort_rad.c stack.c swap.c node.c push.c rotate.c sort_five.c sort_three.c utilities.c ft_substr.c ft_split.c free.c assign_index.c 

SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))



# Object files

OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))



# Output binary

NAME := push_swap



# Rules

all: $(OBJ_DIR) $(NAME)



$(NAME): $(OBJS)

	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) -o $@



# Ensure obj directory is created before compiling objects

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)

	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@



$(OBJ_DIR):

	mkdir -p $(OBJ_DIR)



clean:

	rm -rf $(OBJ_DIR)



fclean: clean

	rm -f $(NAME)



re: fclean all



.PHONY: all clean fclean re
