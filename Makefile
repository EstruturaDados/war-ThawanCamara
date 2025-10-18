BASENAME = war
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDES := -I includes/

SRCS = war.c

OBJS = $(SRCS:.c=.o)

ifeq ($(OS), Windows_NT)
NAME = $(BASENAME).exe
CLEAN_OBJ = if exist $(OBJS) del /Q $(OBJS)
CLEAN_BIN = if exist $(NAME).exe del /Q $(NAME).exe
else
NAME = $(BASENAME)
CLEAN_OBJ = rm -rf $(OBJS)
CLEAN_BIN = rm -rf $(NAME)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $^


clean:
	$(CLEAN_OBJ)

fclean: clean
	$(CLEAN_BIN)

re: fclean all

.PHONY: all clean fclean re
