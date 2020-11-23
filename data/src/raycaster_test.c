#include <stdio.h>
#include <math.h>
#include "raycaster.h"

char	check_hit(int cell_x, int cell_y, t_board board)
{
	return (cell_x <= 0 || cell_x >= (board.cols - 1) ||
		cell_y <= 0 || cell_y >= (board.rows - 1) ? '1' : 0);
}

void test_raycast() {
	s_hit_projection **proy;
	t_board board;
	t_pov	pov;
	t_fov	fov;
	int		rays;
	t_trig  trigs[RAYCASTER_ANGLES];

	ft_precalcule_trigonometrics(trigs);
	ft_print_trigonometrics(trigs);

	board.cols = 24;
	board.rows = 24;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = 60;

	pov.x = 768;
	pov.y = 768;
	pov.dir = 250;
	printf("/// Celdas (%d) . Ancho celda (%d). Fov (%d, %d, %3d). Pov (%d %d %3d)\n", board.cols, board.cell_w, fov.w, fov.h, fov.angle, pov.x, pov.y, pov.dir);

	rays = 0;
	proy = raycast(board, pov, fov, trigs, check_hit);
	while (*(proy + rays)) {
		printf("%d - wh %d wd %c\n", rays, (*(proy + rays))->col_height, (*(proy + rays))->wall_dir);
		rays++;
		free(*proy);
		(*proy) += 1;

	}
	free(proy);
}

void test_all_rays()
{
	s_hit_projection *wall_height;
	t_board board;
	t_pov	pov;
	t_fov	fov;
	t_hit   h;
	int		ray;
	t_trig	trigs[RAYCASTER_ANGLES];


	ft_precalcule_trigonometrics(trigs);

	board.cols = 24;
	board.rows = 24;
	board.cell_w = 64;
	board.data = 0;

	fov.w = 320;
	fov.h = 200;
	fov.angle = 60;

	printf("/// Celdas (%d) . Ancho celda (%d). Fov (%d, %d, %3d)\n", board.cols, board.cell_w, fov.w, fov.h, fov.angle);
	pov.x = 12 * 64;
	pov.y = 12 * 64;
	pov.dir = 292;
	ray = 0;
	while (ray < RAYCASTER_ANGLES) {
		launch_ray(ray, board, pov, trigs, check_hit,  &h);
		wall_height = project_ray(fov, pov, trigs, h);
	printf("%3d: dir(%3d) hit(%7.2f, %7.2f - %2d, %2d - %s) \n", 
			ray, pov.dir, h.x, h.y,  h.cell_x, h.cell_y, h.h ? "--" : "||");
	printf("     wall height: %3d wall_dir: %c\n", wall_height->col_height, wall_height->wall_dir);
		pov.dir ++;
		ray++;
		if (pov.dir >= RAYCASTER_ANGLES)
			pov.dir -= RAYCASTER_ANGLES;
	}
}

int main(void)
{
	test_all_rays();
	//test_raycast();
	return (0);
}