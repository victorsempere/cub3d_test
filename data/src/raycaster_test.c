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
	return (cell_x <= 0 || cell_x >= board.cells ||
		cell_y <= 0 || cell_y >= board.cells ? 1 : 0);
}

void test_project_rays()
{
	t_board board;
	t_pov	pov;
	t_fov	fov;
	t_hit   h;
	s_hit_projection *proj;
	float	fov_dist;


	board.cells = 10;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = 60.0 * M_PI / 180.0;
	fov_dist = (fov.w / 2.0) / tan(fov.angle / 2.0);

	printf("/// Validar horizontal media derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = fov_dist + 63;
	pov.dir = 0;

	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);
	pov.y += fov_dist / 2.0;
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);

	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y =  (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.dir = -M_PI_4;
	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);

	pov.dir = -M_PI_4 - (2.0 * M_PI);
	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);

	pov.dir = M_PI_4;
	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);

}

void test_project_rays_2()
{
	t_board board;
	t_pov	pov;
	t_fov	fov;
	t_hit   h;
	s_hit_projection *proj;
	float	fov_dist;


	board.cells = 10;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = 60.0 * M_PI / 180.0;
	fov_dist = (fov.w / 2.0) / tan(fov.angle / 2.0);

	printf("/// Validar horizontal media derecha\n");
	pov.x = 1438;
	pov.y = 1528;
	pov.dir = 0 - (30.0 * (fov.angle / fov.w));
	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);
	pov.dir = 0;
	while (pov.dir < (2 *(fov.angle / 2.0))) {
		pov.dir += (fov.angle / fov.w);
		launch_ray(board, pov, check_hit, &h);
		proj = project_ray(fov, pov, h);
		printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);
	}

	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = fov_dist + 63;
	pov.dir = 0 - (fov.angle / fov.w);

	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);

	pov.dir += ((60 * M_PI) / 180) / (float)fov.w;
	launch_ray(board, pov, check_hit, &h);
	proj = project_ray(fov, pov, h);
	printf("Projection %d - Dir %d\n", proj->col_height,	proj->wall_dir);
}

void test_all_rays()
{
	t_board board;
	t_pov	pov;
	t_fov	fov;
	t_hit   h;
	s_hit_projection *proj;
	int		ray;


	board.cells = 20;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = 60.0 * M_PI / 180.0;

	printf("/// Celdas (%d) . Ancho celda (%d). Fov (%d, %d, %6.2f)\n", board.cells, board.cell_w, fov.w, fov.h, fov.angle);
	pov.x = board.cell_w * (board.cells >> 1);
	pov.y = board.cell_w * (board.cells >> 1);
	pov.dir = 0;
	ray = 0;
	while (ray < 360) {
		launch_ray(board, pov, check_hit, &h);
		proj = project_ray(fov, pov, h);
		printf("%3d: pov(%4d, %4d) dir (%4.3f). hit(%6.2f, %6.2f) . hit_c(%2d, %2d). Height %3d\n", 
			ray, pov.x, pov.y, pov.dir, h.x, h.y,  h.cell_x, h.cell_y, proj->col_height);
		pov.dir += ((2.0 * M_PI) / 360);
		ray++;
	}
}

void test_launch_rays()
{
	t_board board;
	t_pov	pov;
	t_hit   h;

	board.cells = 10;
	board.cell_w = 64;
	board.data = 0;

	printf("/// Validar horizontal media derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = (board.cells >> 1) * board.cell_w;
	pov.dir = M_PI + M_PI_2;
	launch_ray(board, pov, check_hit, &h);

	printf("/// Validar horizontal media izquierda\n");
	pov.x = 96;
	pov.y = (board.cells >> 1) * board.cell_w;
	pov.dir = M_PI_2;
	launch_ray(board, pov, check_hit, &h);

	printf("/// Validar esquina superior izquierda\n");
	pov.x = 96;
	pov.y = 96;
	pov.dir = M_PI;
	launch_ray(board, pov, check_hit, &h);
	pov.dir = M_PI - M_PI_4;
	launch_ray(board, pov, check_hit, &h);

	printf("/// Validar esquina superior derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = 96;
	pov.dir = M_PI;
	launch_ray(board, pov, check_hit, &h);
	pov.dir = M_PI + M_PI_4;
	launch_ray(board, pov, check_hit, &h);

	printf("/// Validar esquina inferior derecha\n");
	pov.x = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.y = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.dir = 0;
	launch_ray(board, pov, check_hit, &h);
	pov.dir = (2 * M_PI) - M_PI_4;
	launch_ray(board, pov, check_hit, &h);

	printf("/// Validar esquina inferior izquierda\n");
	pov.x = 96;
	pov.y = (board.cells - 1) * board.cell_w + (board.cell_w >> 1);
	pov.dir = 0;
	launch_ray(board, pov, check_hit, &h);
	pov.dir = M_PI_4;
	launch_ray(board, pov, check_hit, &h);
}

void test_raycast()
{
	t_board board;
	t_pov	pov;
	t_fov	fov;

	s_hit_projection **cols;
	int		col;

	board.cells = 10;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = M_PI * 60.0 / 180.0;

	pov.x = board.cells / 2 * board.cell_w;
	pov.y = board.cells / 2 * board.cell_w;
	pov.dir = 0;

	cols = raycast(board, pov, fov, check_hit);
	col = 0;
	while (col < fov.w)
	{
		printf("Col %d - Heigth %d\n", col, (*(cols + col))->col_height);
		col ++;
	}
}

int main(void)
{
	test_all_rays();
	//test_project_rays();
	//test_project_rays_2();
	//test_launch_rays();
	//test_raycast();
	//test_firsthit(cells, cell);
	return (0);
}