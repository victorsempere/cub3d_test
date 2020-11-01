#include <stdio.h>
#include "cub3d_bmp.h"
#include "graphics.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
    t_xvar	*mlx;
	s_image_cfg img;
	const char *file_name = "screenshot.bmp";
	const char *error;

	if (!(mlx = (t_xvar *)mlx_init()))
	{
		printf(" !! KO !!\n");
		exit(1);
	}

	int side = 100;
	int rect = 100;
	int color;
	
	img.width = side;
	img.height = side;
	img.local_endian = is_device_big_endian();
	if (!(img.buff = mlx_new_image(mlx,img.width,img.height)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}

	color = 0x04ff0203;
	ft_draw_rectangle(&img, 0, 0, rect, rect, color);
    if ((error = ft_image_to_bmp(mlx, &img, "red.bmp")))
		printf(" Error: %s\n", error);
	else
		printf("BMP red saved into %s\n", file_name);

	color = 0x0401ff03;
	ft_draw_rectangle(&img, 0, 0, rect, rect, color);
    if ((error = ft_image_to_bmp(mlx, &img, "green.bmp")))
		printf(" Error: %s\n", error);
	else
		printf("BMP green saved into %s\n", file_name);

	color = 0x040102ff;
	ft_draw_rectangle(&img, 0, 0, rect, rect, color);
    if ((error = ft_image_to_bmp(mlx, &img, "blue.bmp")))
		printf(" Error: %s\n", error);
	else
		printf("BMP blue saved into %s\n", file_name);

	mlx_destroy_image(mlx, img.buff);
    exit(0);
}