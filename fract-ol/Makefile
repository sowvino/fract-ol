NAME = fractol

MY_SOURCES = events.c \
             init.c \
             main.c \
             math_utilis.c \
             render.c \
             utilis.c

OBJECTS = $(MY_SOURCES:.c=.o)

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -L/usr/X11/lib -lXext -lX11 -lm

INCS = fractol.h

MINILIBX_DIR = ../minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) $(INCS)
	$(COMPILER) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(INCS)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
