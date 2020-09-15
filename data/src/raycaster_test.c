#include <stdio.h>
#include <math.h>
#include "raycaster.h"

/* void testfirsthit(int cell)
{
	int hx, hy;
	int vx, vy;
	int intersect;
	int cx, cy;
	int px, py, angle;

	px = 64;
	py = 64;
	angle = 0;
	intersect = first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", 
		intersect, px, py, angle, hx, hy, cx, cy);

	angle = M_PI + M_PI - M_PI_4;
	intersect = first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, hx, hy, cx, cy);

	px = 96;
	py = 96;
	angle = 0;
	intersect = first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, hx, hy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_4;
	intersect = first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", 
		intersect, px, py, angle, hx, hy, cx, cy);

	px = 64;
	py = 64;
	angle = M_PI_2;
	intersect = first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_4;
	intersect = first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_2 + M_PI_4;
	intersect = first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);
}
 */
int	check_hit(int cell_x, int cell_y, t_board board)
{
	return (cell_x > 0 && cell_x < board.cells &&
		cell_y > 0 && cell_y < board.cells ? 0 : 1);
}

int main(void)
{
	t_board board;
	t_pov	pov;
	t_hit   *h;

	board.cells = 10;
	board.cell_w = 64;
	board.data = 0;

	printf("/// Validar horizontal media derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = (board.cells >> 1) * board.cell_w;
	pov.dir = M_PI + M_PI_2;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	printf("/// Validar horizontal media izquierda\n");
	pov.x = 96;
	pov.y = (board.cells >> 1) * board.cell_w;
	pov.dir = M_PI_2;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	printf("/// Validar esquina superior izquierda\n");
	pov.x = 96;
	pov.y = 96;
	pov.dir = M_PI;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);
	pov.dir = M_PI - M_PI_4;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	printf("/// Validar esquina superior derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = 96;
	pov.dir = M_PI;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);
	pov.dir = M_PI + M_PI_4;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	printf("/// Validar esquina inferior derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.dir = 0;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);
	pov.dir = (2 * M_PI) - M_PI_4;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	printf("/// Validar esquina inferior izquierda\n");
	pov.x = 96;
	pov.y = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.dir = 0;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);
	pov.dir = M_PI_4;
	h = raycast(board, pov, check_hit);
	if (h)
		free(h);

	//test_firsthit(cells, cell);
	return (0);
}