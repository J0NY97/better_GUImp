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
		update_layers.c

SRCS = $(addprefix $(DIR_S)/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft -L./libft \
		   -I./better_libui -L./better_libui \
		   -I./ft_printf -L./ft_printf \
		   -I$(INC)
LIBS = libft/libft.a ft_printf/libprintf.a better_libui/better_libui.a
FLAGS = -Wall -Wextra -Werror
SDL = -I../include -L../lib -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) $(SDL)
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "guimp was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
