CUB3D_PATH	:= ./toTest
CFLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address -lftprintf -lft -lm -I ${CUB3D_PATH}/src/libft -I ${CUB3D_PATH}/src/libftprintf -I ${CUB3D_PATH}/src/raycaster/ -I ${CUB3D_PATH}/src/parser/ -I ${CUB3D_PATH}/src/MinilibX/X11 -I ${CUB3D_PATH}/src/graphics -I ${CUB3D_PATH}/src/geo2d -I ${CUB3D_PATH}/src/bmp

LDFLAGS 	:= -L ${CUB3D_PATH}/src/MinilibX/X11 -L ${CUB3D_PATH}/src/libft -L ${CUB3D_PATH}/src/libftprintf -lftprintf -lft -lmlx -lXext -lX11

SRC		:= ./src
BIN		:= ./bin
OBJS_CUB:=   ${CUB3D_PATH}/src/raycaster/*.o ${CUB3D_PATH}/src/parser/*.o ${CUB3D_PATH}/src/bmp/*.o

all: bmp_test parser_test raycaster_test

compile_libftprintf:
	${MAKE} -C ${CUB3D_PATH}/src/libftprintf
	${MAKE} -C ${CUB3D_PATH}/src/libftprintf bonus

compile_libft:
	${MAKE} -C ${CUB3D_PATH}/src/libft
	${MAKE} -C ${CUB3D_PATH}/src/libft bonus

bmp_test : compile_libft compile_libftprintf ${SRC}/bmp_test.o build_cub3d
	${CC} -o ${BIN}/bmp_test ${SRC}/bmp_test.o ${OBJS_CUB} ${CFLAGS} ${LDFLAGS}

parser_test : compile_libft compile_libftprintf ${SRC}/parser_test.o build_cub3d
	${CC} -o ${BIN}/parser_test ${SRC}/parser_test.o ${OBJS_CUB} ${CFLAGS} ${LDFLAGS}

raycaster_test : ${SRC}/raycaster_test.o build_cub3d
	${CC} -o ${BIN}/raycaster_test ${SRC}/raycaster_test.o ${OBJS_CUB} ${CFLAGS} ${LDFLAGS}

re_build_cub3d:
	${MAKE} -C ${CUB3D_PATH} re

build_cub3d:
	${MAKE} -C ${CUB3D_PATH}

clean:
	${RM} ./src/parser_test.o ./src/raycaster_test.o
	${MAKE} -C ${CUB3D_PATH} clean
	
fclean: clean
	${RM} ${BIN}/raycaster_test ${BIN}/parser_test
	${MAKE} -C ${CUB3D_PATH} fclean

re: fclean all