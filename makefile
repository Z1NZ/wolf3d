CC    = gcc  -Wall -Wextra -Werror -Ofast

RM    = rm -f

NAME    = wolf3d

SRC    = wolf3d.c\
		 map_pars.c\
		 raycaster.c\
		 control.c\
		 draw.c\
		 loop.c\

OBJS    = $(SRC:.c=.o)
SRCDIR 	= ./srcs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
X11_DIR = -I./includes/ -I/usr/X11R6/include \
        -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME):
	@make -C libftprintf
	@make -C minilibx_macos/
	@$(CC) $(SRCS) -L./libftprintf/libft/ -lft -I./includes/ -L./minilibx_macos/ -lmlx $(X11_DIR) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C libftprintf

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libftprintf

re: fclean all

.PHONY: all clean fclean re
