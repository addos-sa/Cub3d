# --- Variables ---
NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Werror -Wextra 

# --- Directories and Libraries ---
MLX_DIR		= ./src/MLX42
SRC_DIR		= src
OBJ_DIR		= obj
LIBS		= -lreadline
PRINTF_DIR = ./src/ft_printf
PRINTF_LIBRARY = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = ./src/libft
LIBFT_LIBRARY = $(LIBFT_DIR)/libft.a
UNAME_S := $(shell uname -s)

# --- Source Files ---
# Common source files used by both main executable and tests
COMMON_SRCS = 

# Main executable specific source
MAIN_SRC_FILE = main.c

# --- Object Files ---
# Note: No addprefix is used here. Paths are constructed directly.
COMMON_OBJS	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(COMMON_SRCS))
MAIN_OBJ	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRC_FILE))

# --- Rules ---
##for compiling the mlx depending of the system

ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -pthread
endif
all: $(NAME)

# Main executable
$(NAME): $(MAIN_OBJ) $(COMMON_OBJS) $(PRINTF_LIBRARY) $(LIBFT_LIBRARY)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(COMMON_OBJS) $(PRINTF_LIBRARY) $(LIBFT_LIBRARY) -o $(NAME) $(MLX_FLAGS)
	@echo "$(NAME) compiled!"

# Generic rule to compile any .c from src to an .o in obj
$(PRINTF_LIBRARY) :
	make -C $(PRINTF_DIR)
$(LIBFT_LIBRARY) :
	make -C $(LIBFT_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_DIR)/build
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "Full clean complete."

re: fclean all

.PHONY: all clean fclean re