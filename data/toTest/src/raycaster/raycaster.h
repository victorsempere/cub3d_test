#ifndef _RAYCASTER_H
# define _RAYCASTER_H

#  include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define MARGIN 0.0001
# define ZERO (0 + MARGIN)

typedef struct 	s_board
{
	int         cells;
	int         cell_w;
	char        *data;
}               t_board;

typedef struct  s_hit 
{
	int         x;
	int         y;
	int         cell_x;
	int         cell_y;
}		        t_hit;

typedef struct  s_pov
{
	int         x;
	int         y;
	float		dir;
}               t_pov;


t_hit			*raycast(t_board board, t_pov pov,
	int (*check_hit)(int cell_x, int cell_y, t_board board));
void			get_cell(int width, int height, int x, int y, int *cx, int *cy);
char			match_next_horizontal_intersection(int height, int x, int y, float dir, int *ax, int *ay);
char			first_horizontal_intersection(int height, t_pov pov, t_hit *hit);
char			first_vertical_intersection(int height, t_pov pov, t_hit *hit);
char			match_next_vertical_intersection(int width, int x, int y, float dir, int *ax, int *ay);

#endif