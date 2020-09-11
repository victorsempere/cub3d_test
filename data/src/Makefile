NAME	:= main
CFLAGS	:= -Wall -Werror -Wextra -g -fsanitize=address
LDFLAGS :=

BIN		:= ../bin
SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${BIN}/${NAME} ${OBJS}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all