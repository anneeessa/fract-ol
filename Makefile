NAME	=	fractol
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS 	=	fractol.c mandelbrot.c julia.c utils.c render.c events.c tricorn.c

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Compilation finished: ./$(NAME) [1, 2, <value between -2 & 2> <value between -2 & 2>]"

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re