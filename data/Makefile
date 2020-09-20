NAME	:= raycaster_test
CUB3D_PATH	:= ./toTest
CFLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address -lm -I ${CUB3D_PATH}/src/raycaster/

LDFLAGS 	:=

BIN		:= ./bin
SRCS	:= ./src/raycaster_test.c
OBJS	:= ${SRCS:.c=.o}
OBJS_CUB:= ${CUB3D_PATH}/src/raycaster/*.o

all: ${NAME}

${NAME} : ${OBJS} build_cub3d
	${CC} -o ${BIN}/${NAME} ${OBJS} ${OBJS_CUB} ${CFLAGS}

re_build_cub3d:
	${MAKE} -C ${CUB3D_PATH} re

build_cub3d:
	${MAKE} -C ${CUB3D_PATH}

clean:
	${RM} ${OBJS}
	${MAKE} -C ${CUB3D_PATH} clean
	
fclean: clean
	${RM} ${BIN}/${NAME}
	${MAKE} -C ${CUB3D_PATH} fclean

re: fclean all