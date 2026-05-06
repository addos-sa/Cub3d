NAME = cub3D
SAN_NAME = cub3D_san
B_NAME = cub3D_bonus
B_SAN_NAME = cub3D_bonus_san

SRC_DIR = src/
B_SRC_DIR = src/bonus/
OBJ_DIR = obj/
B_OBJ_DIR = obj/bonus/
OBJ_SAN_DIR = obj_san/
B_OBJ_SAN_DIR = obj_san/bonus/
INC_DIR = include/
B_INC_DIR = include/bonus/

LIBMLX = lib/MLX42/
PRINTF_DIR = lib/ft_printf/
LIBFT_DIR = lib/libft/

PRINTF = $(PRINTF_DIR)libftprintf.a
LIBFT = $(LIBFT_DIR)libft.a

INC = -I $(INC_DIR) -I $(PRINTF_DIR) -I $(LIBFT_DIR) -I $(LIBMLX)include
B_INC = -I $(B_INC_DIR) -I $(PRINTF_DIR) -I $(LIBFT_DIR) -I $(LIBMLX)include

CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIC
SANFLAGS = $(CFLAGS) -fsanitize=address
RM = rm -f

LIBS = $(LIBMLX)build/libmlx42.a -ldl -lglfw -pthread -lm

MAIN_SRCS =			$(SRC_DIR)main/bad.c \
					$(SRC_DIR)main/free.c \
					$(SRC_DIR)main/inits.c \
					$(SRC_DIR)main/key_press.c \
					$(SRC_DIR)main/main.c \
					$(SRC_DIR)main/utils.c

PARSE_SRCS =		$(SRC_DIR)parse/get_color.c \
					$(SRC_DIR)parse/get_map.c \
					$(SRC_DIR)parse/parse_map.c \
					$(SRC_DIR)parse/parse_paths.c \
					$(SRC_DIR)parse/parse_player.c \
					$(SRC_DIR)parse/parse.c

RAYCAST_SRCS =		$(SRC_DIR)ray_casting/calculations.c \
					$(SRC_DIR)ray_casting/draw_funtions.c \
					$(SRC_DIR)ray_casting/graphics.c

VALIDATION_SRCS =	$(SRC_DIR)validation/validation_colours.c \
					$(SRC_DIR)validation/validation_map.c \
					$(SRC_DIR)validation/validation_textures.c \
					$(SRC_DIR)validation/validation.c

SRCS = $(MAIN_SRCS) $(PARSE_SRCS) $(RAYCAST_SRCS) $(VALIDATION_SRCS)

OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_SAN = $(patsubst $(SRC_DIR)%.c,$(OBJ_SAN_DIR)%.o,$(SRCS))

B_EXTRA_SRCS =		$(B_SRC_DIR)extra/door.c \
					$(B_SRC_DIR)extra/draw_minimap.c \
					$(B_SRC_DIR)extra/mouse.c

B_MAIN_SRCS =		$(B_SRC_DIR)main/bad_bonus.c \
					$(B_SRC_DIR)main/free_bonus.c \
					$(B_SRC_DIR)main/inits_bonus.c \
					$(B_SRC_DIR)main/key_press_bonus.c \
					$(B_SRC_DIR)main/main_bonus.c \
					$(B_SRC_DIR)main/utils_bonus.c

B_PARSE_SRCS =		$(B_SRC_DIR)parse/get_color_bonus.c \
					$(B_SRC_DIR)parse/get_map_bonus.c \
					$(B_SRC_DIR)parse/parse_map_bonus.c \
					$(B_SRC_DIR)parse/parse_paths_bonus.c \
					$(B_SRC_DIR)parse/parse_player_bonus.c \
					$(B_SRC_DIR)parse/parse_bonus.c

B_RAYCAST_SRCS =	$(B_SRC_DIR)ray_casting/calculations_bonus.c \
					$(B_SRC_DIR)ray_casting/draw_funtions_bonus.c \
					$(B_SRC_DIR)ray_casting/graphics_bonus.c

B_VALIDATION_SRCS =	$(B_SRC_DIR)validation/validation_colours_bonus.c \
					$(B_SRC_DIR)validation/validation_map_bonus.c \
					$(B_SRC_DIR)validation/validation_textures_bonus.c \
					$(B_SRC_DIR)validation/validation_bonus.c

B_SRCS = $(B_EXTRA_SRCS) $(B_MAIN_SRCS) $(B_PARSE_SRCS) $(B_RAYCAST_SRCS) $(B_VALIDATION_SRCS)

B_OBJS = $(patsubst $(B_SRC_DIR)%.c,$(B_OBJ_DIR)%.o,$(B_SRCS))
B_OBJS_SAN = $(patsubst $(B_SRC_DIR)%.c,$(B_OBJ_SAN_DIR)%.o,$(B_SRCS))

all: libmlx $(LIBFT) $(PRINTF) $(NAME)

sanitize: libmlx $(LIBFT) $(PRINTF) $(SAN_NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)build && make -C $(LIBMLX)build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LIBS) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

$(SAN_NAME): $(OBJS_SAN) $(LIBFT) $(PRINTF)
	@$(CC) $(SANFLAGS) $(OBJS_SAN) $(LIBFT) $(PRINTF) $(LIBS) -o $(SAN_NAME)
	@echo "Compiled $(SAN_NAME) with AddressSanitizer successfully!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_SAN_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(SANFLAGS) $(INC) -c $< -o $@

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(B_INC) -c $< -o $@

$(B_OBJ_SAN_DIR)%.o: $(B_SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(SANFLAGS) $(B_INC) -c $< -o $@

bonus: libmlx $(LIBFT) $(PRINTF) $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) $(PRINTF) $(LIBS) -o $(B_NAME)
	@echo "Compiled $(B_NAME) successfully! ✅"

bonus_sanitize: libmlx $(LIBFT) $(PRINTF) $(B_SAN_NAME)

$(B_SAN_NAME): $(B_OBJS_SAN) $(LIBFT) $(PRINTF)
	@$(CC) $(SANFLAGS) $(B_OBJS_SAN) $(LIBFT) $(PRINTF) $(LIBS) -o $(B_SAN_NAME)
	@echo "Compiled $(B_SAN_NAME) with AddressSanitizer successfully!"

clean:
	@$(RM) -r $(OBJ_DIR) $(OBJ_SAN_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "Cleaned object files."

fclean: clean
	@$(RM) $(NAME) $(SAN_NAME) $(B_NAME) $(B_SAN_NAME) 
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "Cleaned everything."

re: fclean all

resan: fclean sanitize

.PHONY: all sanitize libmlx clean fclean re resan