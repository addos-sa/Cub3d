# --- Variables ---
NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Werror -Wextra 

# --- Directories and Libraries ---
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I includes -I $(LIBFT_DIR)
LIBS		= -lreadline

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
all: $(NAME)

# Main executable
$(NAME): $(MAIN_OBJ) $(COMMON_OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(MAIN_OBJ) $(COMMON_OBJS) -L$(LIBFT_DIR) -lft $(LIBS)
	@echo "cub3D compiled!"

# Generic rule to compile any .c from src to an .o in obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Full clean complete."

re: fclean all

.PHONY: all clean fclean re test
