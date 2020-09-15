#include "raycaster.h"

void get_cell(int width, int height, int x, int y, int *cx, int *cy)
{
	*cx = floor(x / width);
	*cy = floor(y / height);
}

char match_next_horizontal_intersection(int height, int x, int y, float dir, int *ax, int *ay)
{
	float angle;

	angle = cos(dir);
	if (angle > ZERO)
		*ay -= height;
	else if (angle < -ZERO)
		*ay += height;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		*ax = x;
	else
		*ax = x + (y - *ay) * tan(dir);
	return (1);
}

char first_horizontal_intersection(int height, t_pov pov, t_hit *hit)
{
	float angle;

	angle = cos(pov.dir);
	if (angle > ZERO)
		hit->y = floor(pov.y / height) * height - 1;
	else if (angle < -ZERO)
		hit->y = floor(pov.y / height) * height + height;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		hit->x = pov.x;
	else
		hit->x = pov.x + (pov.y - hit->y) * tan(pov.dir);
	get_cell(height, height, hit->x, hit->y, &hit->cell_x, &hit->cell_y);
	return (1);
}

char first_vertical_intersection(int width, t_pov pov, t_hit *hit)
{
	float angle;

	angle = sin(pov.dir);
	if (angle > ZERO)
		hit->x = floor(pov.x / width) * width + width;
	else if (angle < -ZERO)
		hit->x = floor(pov.x / width) * width - 1;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		hit->y = pov.y;
	else
		hit->y = pov.y + (pov.x - hit->x) * tan(pov.dir);
	get_cell(width, width, hit->x, hit->y, &hit->cell_x, &hit->cell_y);
	return (1);
}

char match_next_vertical_intersection(int width, int x, int y, float dir, int *ax, int *ay)
{
	float angle;

	angle = sin(dir);
	if (angle > ZERO)
		*ax += width;
	else if (angle < -ZERO)
		*ax -= width;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		*ay = y;
	else
		*ay = y + (x - *ax) * tan(dir);
	return (1);
}

void	assign_hit(t_hit src, t_hit *tgt)
{
	tgt->cell_x = src.cell_x;
	tgt->cell_y = src.cell_y;
	tgt->x = src.x;
	tgt->y = src.y;
}

int		distance(t_hit h)
{
	int	dist;
	
	dist = (h.x + h.y);
	if (dist < 0)
		dist = -dist;
	return (dist);
}

int		launch_ray_checking_horizontal_intersections(t_board board, t_pov pov, t_hit *h, 
	int (*check_hit)(int cell_x, int cell_y, t_board board))
{
	char inter_h;

	get_cell(board.cell_w, board.cell_w, pov.x, pov.y, &h->cell_x, &h->cell_y);
	printf("Partimos de (%d, %d)\n", h->cell_x, h->cell_y);
	if ((inter_h = first_horizontal_intersection(board.cell_w, pov, h)))
		printf("    Intersección H %d - (%d, %d)\n", inter_h, h->cell_x, h->cell_y);
	while (inter_h)
	{
		if (inter_h && check_hit(h->cell_x, h->cell_y, board))
			return (1);
		inter_h = match_next_horizontal_intersection(board.cell_w, h->x, h->y, pov.dir, &h->x, &h->y);
		get_cell(board.cell_w, board.cell_w, h->x, h->y, &h->cell_x, &h->cell_y);
		printf("    Intersection H %d - (%d, %d)\n", inter_h, h->cell_x, h->cell_y);
	}
	return (0);
}

int		find_vertical_intersection(t_board board, t_pov pov, t_hit *h, 
	int (*check_hit)(int cell_x, int cell_y, t_board board))
{
	char inter_v;

	get_cell(board.cell_w, board.cell_w, pov.x, pov.y, &h->cell_x, &h->cell_y);
	printf("Partimos de (%d, %d)\n", h->cell_x, h->cell_y);
	if ((inter_v = first_vertical_intersection(board.cell_w, pov, h)))
		printf("    Intersección V %d - (%d, %d)\n", inter_v, h->cell_x, h->cell_y);
	while (inter_v)
	{
		if (inter_v && check_hit(h->cell_x, h->cell_y, board))
			return (1);
		inter_v = match_next_vertical_intersection(board.cell_w, h->x, h->y, pov.dir, &h->x, &h->y);
		get_cell(board.cell_w, board.cell_w, h->x, h->y, &h->cell_x, &h->cell_y);
		printf("    Intersection V %d - (%d, %d)\n", inter_v, h->cell_x, h->cell_y);
	}
	return (0);
}

t_hit	*raycast(t_board board, t_pov pov,
    int (*check_hit)(int cell_x, int cell_y, t_board board))
{
	t_hit	*hit;
	t_hit	h;
	t_hit	v;

	if (!(hit = malloc(sizeof(t_hit))))
		return (0);

	launch_ray_checking_horizontal_intersections(board, pov, &h, check_hit);
	find_vertical_intersection(board, pov, &v, check_hit);
	if (distance(h) < distance(v))
		assign_hit(h, hit);
	else
		assign_hit(v, hit);
	return (hit);
}
