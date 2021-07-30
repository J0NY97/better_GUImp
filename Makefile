NAME = guimp
DIR_S = ./srcs
INC	=	.
SRC	=	main.c \
		draw.c \
		text_to_screen.c \
		zoom_and_move.c \
		shapes.c \
		guimp_quit.c \
		load_icons.c \
		save_img.c \
		add_new_layer.c \
		reset_workspace.c \
		open_button.c \
		drag_drop.c \
		init_shape_button.c \
		init_elem_group.c \
		init_drop_down.c \
		init_slider.c \
		init_tool_buttons.c \
		init_layers.c \
		init_windows.c \
		init_utility_elems.c \
		init_brush.c \
		update_hidden_surface.c \
		update_brush.c \
		flood_fill.c \
		ft_create_square.c \
		update_layers.c

SRCS = $(addprefix $(DIR_S)/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libs/libft -L./libs/libft \
		   -I./libs/better_libui -L./libs/better_libui \
		   -I./libs/libpf -L./libs/libpf \
		   -I$(INC)
LIBS = -lui -lpf -lft 
FLAGS = -Wall -Wextra -Werror
SDL = -I./libs/SDL/include -L./libs/SDL/lib -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) $(LIBS) $(SDL)
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "guimp was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
