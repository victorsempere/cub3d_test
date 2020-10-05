CUB3D_PATH	:= ./toTest
CFLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address -lm -I ${CUB3D_PATH}/src/raycaster/ -I ${CUB3D_PATH}/src/parser/ -I ${CUB3D_PATH}/src/libft/

LDFLAGS 	:=

SRC		:= ./src
BIN		:= ./bin
OBJS_CUB:= ${CUB3D_PATH}/src/libft/*.o ${CUB3D_PATH}/src/raycaster/*.o ${CUB3D_PATH}/src/parser/*.o

all: parser_test raycaster_test

parser_test : ${SRC}/parser_test.o build_cub3d
	${CC} -o ${BIN}/parser_test ${SRC}/parser_test.o ${OBJS_CUB} ${CFLAGS}

raycaster_test : ${SRC}/raycaster_test.o build_cub3d
	${CC} -o ${BIN}/raycaster_test ${SRC}/raycaster_test.o ${OBJS_CUB} ${CFLAGS}

re_build_cub3d:
	${MAKE} -C ${CUB3D_PATH} re

build_cub3d:
	${MAKE} -C ${CUB3D_PATH}

clean:
	${RM} ${OBJS}
	${MAKE} -C ${CUB3D_PATH} clean
	
fclean: clean
	${RM} ${BIN}/raycaster_test ${BIN}/parser_test
	${MAKE} -C ${CUB3D_PATH} fclean

re: fclean all