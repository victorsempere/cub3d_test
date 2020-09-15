NAME	:= cub3d
CFLAGS	:= -Wall -Werror -Wextra -g -fsanitize=address -lm -I ./src/raycaster -DDEBUG
LDFLAGS :=

BIN		:= ./bin
SRCS	:= ./src/main.c ./src/raycaster/raycaster.c

OBJS	:= ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${CC} -o ${BIN}/${NAME} ${OBJS} ${CFLAGS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${BIN}/${NAME}

re: fclean all