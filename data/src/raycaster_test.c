#include <stdio.h>
#include <math.h>
#include "raycaster.h"

void testfirsthit(int cell)
{
	int hx, hy;
	int vx, vy;
	char intersect;
	int cx, cy;
	int px, py, angle;

	px = 64;
	py = 64;
	angle = 0;
	intersect = match_first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", 
		intersect, px, py, angle, hx, hy, cx, cy);

	angle = M_PI + M_PI - M_PI_4;
	intersect = match_first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, hx, hy, cx, cy);

	px = 96;
	py = 96;
	angle = 0;
	intersect = match_first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, hx, hy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_4;
	intersect = match_first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	get_cell(cell, cell, hx, hy, &cx, &cy);
	printf("horizontal %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", 
		intersect, px, py, angle, hx, hy, cx, cy);

	px = 64;
	py = 64;
	angle = M_PI_2;
	intersect = match_first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_4;
	intersect = match_first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);

	px = 96;
	py = 96;
	angle = M_PI_2 + M_PI_4;
	intersect = match_first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	get_cell(cell, cell, vx, vy, &cx, &cy);
	printf("vertical %d - pos(%d, %d) ang(%d) - firsthit(%d, %d) firsthit cell(%d, %d)\n", intersect, px, py, angle, vx, vy, cx, cy);
}

int main(void)
{
	int cell;
	int cells;
	int px, py;

	cells = 10;
	cell = 64;

	printf("/// Validar horizontal media derecha\n");
	px = (cells - 1) * cell + (cell >> 1);
	py = (cells >> 1) * cell;
	raycast(cells, cell, px, py, 2 * M_PI - M_PI_2);

	printf("/// Validar horizontal media izquierda\n");
	px = 96;
	py = (cells >> 1) * cell;
	raycast(cells, cell, px, py, M_PI_2);

	printf("/// Validar esquina superior izquierda\n");
	px = 96;
	py = 96;
	raycast(cells, cell, px, py, M_PI);
	raycast(cells, cell, px, py, M_PI - M_PI_4);

	printf("/// Validar esquina superior derecha\n");
	px = (cells - 1) * cell + (cell >> 1);
	py = 96;
	raycast(cells, cell, px, py, M_PI);
	raycast(cells, cell, px, py, M_PI + M_PI_4);

	printf("/// Validar esquina inferior derecha\n");
	px = (cells - 1) * cell + (cell >> 1);
	py = (cells - 1) * cell + (cell >> 1);
	raycast(cells, cell, px, py, 0);
	raycast(cells, cell, px, py, (2 * M_PI) - M_PI_4);

	printf("/// Validar esquina inferior izquierda\n");
	px = 96;
	py = (cells - 1) * cell + (cell >> 1);
	raycast(cells, cell, px, py, 0);
	raycast(cells, cell, px, py, M_PI_4);

	//test_firsthit(cells, cell);
	return (0);
}