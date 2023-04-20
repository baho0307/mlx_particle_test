NAME = test
CC = gcc
SRCS = srcs/particle.c srcs/draw.c srcs/space.c srcs/program.c srcs/render.c srcs/vector.c main.c
OBJS = $(SRC:.c=.o)
COMP = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: fclean $(NAME)
	@echo Done!

$(NAME):
	@make -C ./mlx_linux
	@$(CC) $(SRCS) -o $(NAME) $(COMP) $(LINK)
	@echo Program Created!

clean:
	@rm -f $(OBJS)
	@echo Objects Cleaned!

fclean: clean
	@rm -f $(NAME)
	@echo Program Cleaned!

.PHONY: clean fclean
