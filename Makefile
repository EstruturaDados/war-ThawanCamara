NAME = war
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = war.c
OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
