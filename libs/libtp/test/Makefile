NAME = test

SRCS = \
	./main.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = \
	-I../ \

LIB_FOLDERS = \
	-L../ \

LIB = -ltp -lpthread

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) $(LIB_FOLDERS) $(LIB) $(FLAGS)
	@echo "$(NAME) was successfully created."

clean:
	@rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean:
	@rm -f $(NAME)
	@echo "$(NAME) was fcleaned."

re: fclean $(LIBS) all

.PHONY: clean, all, re, fclean
