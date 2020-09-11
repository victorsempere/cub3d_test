#ifndef _RAYCASTER_H
# define _RAYCASTER_H

# include <stdio.h>
# include <math.h>

# define MARGIN 0.0001
# define ZERO (0 + MARGIN)

void raycast(int cells, int cell, int px, int py, float angle);
void get_cell(int width, int height, int x, int y, int *cx, int *cy);
char match_next_horizontal_intersection(int height, int x, int y, float dir, int *ax, int *ay);
char match_first_horizontal_intersection(int height, int x, int y, float dir, int *ax, int *ay);
char match_first_vertical_intersection(int width, int x, int y, float dir, int *ax, int *ay);
char match_next_vertical_intersection(int width, int x, int y, float dir, int *ax, int *ay);

#endif