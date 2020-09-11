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

char match_first_horizontal_intersection(int height, int x, int y, float dir, int *ax, int *ay)
{
	float angle;

	angle = cos(dir);
	if (angle > ZERO)
		*ay = floor(y / height) * height - 1;
	else if (angle < -ZERO)
		*ay = floor(y / height) * height + height;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		*ax = x;
	else
		*ax = x + (y - *ay) * tan(dir);
	return (1);
}

char match_first_vertical_intersection(int width, int x, int y, float dir, int *ax, int *ay)
{
	float angle;

	angle = sin(dir);
	if (angle > ZERO)
		*ax = floor(x / width) * width + width;
	else if (angle < -ZERO)
		*ax = floor(x / width) * width - 1;
	else
		return (0);
	angle = angle < 0 ? -angle : angle;
	if (angle >= (1 - MARGIN) && angle <= (1 + MARGIN))
		*ay = y;
	else
		*ay = y + (x - *ax) * tan(dir);
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

void raycast(int cells, int cell, int px, int py, float angle)
{
	int hx, hy;
	int vx, vy;
	int cx, cy;
	int cvx, cvy;
	char inter_h, inter_v;

	get_cell(cell, cell, px, py, &cx, &cy);
	printf("Partimos de (%d, %d)\n", cx, cy);
	inter_h = match_first_horizontal_intersection(cell, px, py, angle, &hx, &hy);
	inter_v = match_first_vertical_intersection(cell, px, py, angle, &vx, &vy);
	if (inter_h || inter_v)
	{
		if (inter_h)
		{
			get_cell(cell, cell, hx, hy, &cx, &cy);
			printf("    Intersección H %d - (%d, %d)\n", inter_h, cx, cy);
		}
		if (inter_v)
		{
			get_cell(cell, cell, vx, vy, &cvx, &cvy);
			printf("    Intersección V %d - (%d, %d)\n", inter_v, cvx, cvy);
		}
		while ((inter_h && (cx > 0 && cx < cells) && (cy > 0 && cy < cells)) ||
			(inter_v && (cvx > 0 && cvx < cells) && (cvy > 0 && cvy < cells)))
		{
			if (inter_h)
			{
				inter_h = match_next_horizontal_intersection(cell, hx, hy, angle, &hx, &hy);
				get_cell(cell, cell, hx, hy, &cx, &cy);
				printf("    Intersection H %d - (%d, %d)\n", inter_h, cx, cy);
			}

			if (inter_v)
			{
				inter_v = match_next_vertical_intersection(cell, vx, vy, angle, &vx, &vy);
				get_cell(cell, cell, vx, vy, &cvx, &cvy);
				printf("    Intersection V %d - (%d, %d)\n", inter_v, cvx, cvy);
			}
		}
	}
}
