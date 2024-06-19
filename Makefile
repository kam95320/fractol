# Das Progamm
NAME			=	fractol

# Compiler
CC				=	cc
CFLAGS			=	-g3 -Wall -Werror -Wextra -MMD
LDFLAGS			=	-L $(LIBFT_PATH) -lft
MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm

# Libft
LIBFT_PATH		=	libs/libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH		=	libs/minilibx-linux/
MLX_NAME		=	libmlx.a
MLX				=	$(MLX_PATH)$(MLX_NAME)

HEAD			=	-I ./includes/ \
					-I ./libs/libft/ \
					-I ./libs/minilibx-linux/

DEPS			=	${OBJS:.o=.d}

# Sources
SRCS_PATH		=	srcs
SRCS_NAMES		=	calcul_complex_map.c\
					colori.c\
					events.c \
					init.c\
					main.c \
					render.c \
					atodbl.c \
					ft_strcmp.c
			
SRCS			=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))
					
# Objects
OBJS_PATH		=	objs
OBJS_NAMES		=	$(SRCS_NAMES:.c=.o)
OBJS			=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

# -fsanitize=address

MAKEFLAGS		=	--no-print-directory

all	:	$(MLX) $(LIBFT) ${NAME}

$(OBJS_PATH)/%.o	: $(SRCS_PATH)/%.c
		@mkdir -p $(OBJS_PATH)
		@mkdir -p $(OBJS_PATH)/fractal/
		@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(LIBFT)	:
		@echo "Download Libft"
		@make -sC $(LIBFT_PATH)

$(MLX)		: 
		@echo "Download MiniLibX"
		@make -sC $(MLX_PATH)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
		@echo "Download the fractal"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(LDFLAGS) $(MLXFLAGS)
		@echo "You'r fractal is ready"

clean:
	@echo "Clean all file .o"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	

fclean:	clean
	@echo "erase the fractol"
	@rm -rf $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re
