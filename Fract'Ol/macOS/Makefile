NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX = libmlx.a
PATH_MINILIBX = minilibx_macos

MLXFLAGS = -framework OpenGL -framework AppKit

PRINTF = libftprintf.a
PATH_PRINTF = Printf_fd

SRC =	ft_fractol.c			\
	ft_fractol_next.c		\
	ft_fractol_2.c			\
	ft_mandelbrot.c			\
	ft_julia.c			\
	ft_math.c			\
	ft_macros.c			\
	ft_macros_next.c		\
	ft_lib.c			\
	Get_Next_Line/get_next_line.c

OBJ = $(SRC:.c=.o)

NORMINETTE =	*.c		\
		*.h		\
		Get_Next_Line	\
		Printf_fd

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(PATH_PRINTF) -lftprintf -L $(PATH_MINILIBX) -lmlx $(MLXFLAGS)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

bonus: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PATH_PRINTF)

$(MINILIBX):
	$(MAKE) -C $(PATH_MINILIBX)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(PATH_PRINTF) clean
	@$(MAKE) -C $(PATH_MINILIBX) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@$(MAKE) -C $(PATH_MINILIBX) clean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 19 ft_fractol.h
	@echo $(RESET)

norm:
	@norminette $(NORMINETTE)

.PHONY: all clean fclean re rf s help norm
