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

	int side = 10;
	int rect = 2;
	int color = 0x04ff0203;
	
	img.width = side;
	img.height = side;
	img.local_endian = is_device_big_endian();
	if (!(img.buff = mlx_new_image(mlx,img.width,img.height)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	//int red = mlx_get_color_value(mlx, (0xff << 24));
	ft_draw_rectangle(&img, 0, 0, rect, rect, color);
    if ((error = ft_image_to_bmp(mlx, &img)))
		printf(" Error: %s\n", error);
	else
		printf("BMP saved into %s\n", file_name);
	void *win = mlx_new_window(mlx, side, side, "Prueba");
	mlx_put_image_to_window(mlx, win, img.buff, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.buff);
    exit(0);
}