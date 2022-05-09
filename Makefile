NAME = so_long

CC = clang

CFLAGS =  -Wall -Wextra -Werror

SRCS =	srcs/main.c \
		srcs/errors.c \
		srcs/drawing.c \
		srcs/parsing.c \
		srcs/end_of_game.c \
		srcs/window_checker.c \
		srcs/moves.c \
		srcs/inits.c

_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_END=	$'\033[0m

OBJ = $(SRCS:.c=.o)
MLX = -lmlx -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
		@make -C ./libft
		@echo "$(_GREEN)Libft compiled$(_END)"
		@make -C ./ft_printf
		@echo "$(_GREEN)Ft_printf compiled$(_END)"
		@make -C mlx_linux all
			$(CC) $(CFLAGS) $(OBJ) $(MLX) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)
		@echo "$(_GREEN)Executable created : so_long$(_END)"

%o: %.c
	$(CC) $(FLAGS) -I inc -Imlx_linux -O3 -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@make -C ./ft_printf fclean
	@make -C ./libft fclean
	@echo "$(_RED).o files removed$'\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)Executable removed$'\033[0m"

re: fclean all

.PHONY : all bonus clean fclean re
