#include <stdio.h>
#include "cub3d_bmp.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
    t_xvar	*mlx;
	s_image_cfg img;
	const char *file_name = "screenshot.bmp";
	const char *error;
	int a;

	if (!(mlx = (t_xvar *)mlx_init()))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	a = 0x11223344;
	img.width = 1;
	img.height = 1;
	img.local_endian = (((unsigned char *)&a)[0] == 0x11 ? 1 : 0);
	if (!(img.buff = mlx_new_image(mlx,1,1)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	
    if ((error = ft_image_to_bmp(mlx, &img)))
		printf(" Error: %s\n", error);
	else
		printf("BMP saved into %s\n", file_name);
	mlx_destroy_image(mlx, img.buff);
    exit(0);
}