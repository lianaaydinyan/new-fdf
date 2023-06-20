#include "fdf.h"

void	zooming(t_point *ket1 , t_point *ket2)
{
	ket1->x *= 30;
	ket1->y *= 30;
	// ket1->z *= 10;
	ket2->x *= 30;
	ket2->y *= 30;
	// ket2->z *= 10
}

void	define_heigth(t_mapolo *map, t_point *ket1, t_point *ket2)
{
	ket1->z = map->arr[(int)ket1->y][(int)ket1->x];
	ket2->z = map->arr[(int)ket2->y][(int)ket2->x];
}

void	define_colors( t_point *ket1, t_point *ket2)
{
	if (ket1->z != 0 || ket2->z != 0)
		ket1->color = 0x00dd9fe;
	else
		ket1->color = 0xffffff;
}

//hookery 
//leakery
//colors
//3d
//file- .fdf

void	rotating(t_mapolo *map, t_point *ket1, t_point *ket2)
{
	ket1->x = (ket1->x - ket1->y) * cos(map->alfa);
	ket1->y = (ket1->x + ket1->y) * sin(map->alfa) - ket1->z;
	ket2->x = (ket2->x - ket2->y) * cos(map->alfa);
	ket2->y = (ket2->x + ket2->y) * sin(map->alfa) - ket2->z;
}

//main - mej alfa = 

void	draw_line(t_mapolo *map, t_data img, t_point ket1, t_point ket2)
{
	float		delta_x;
	float		delta_y;
	float		max_detlas;

	define_heigth(map, &ket1, &ket2);
	rotating(map, &ket1, &ket2);
	define_colors(&ket1, &ket2);
	zooming(&ket1, &ket2);
	delta_x = ket2.x - ket1.x;
	delta_y = ket2.y - ket1.y;
	max_detlas = malenaa(fabsf(delta_x), fabsf(delta_y));
	delta_x /= max_detlas;
	delta_y /= max_detlas;
	while ((int)(ket2.x - ket1.x) || (int)(ket2.y - ket1.y))
	{
		my_mlx_pixel_put(&img, ket1.x, ket1.y , ket1.color);
		ket1.x += delta_x;
		ket1.y += delta_y;
	}
}

float	malenaa(float	x, float y)
{
	if (x > y)
		return (x);
	return (y);
}


void	draw_map2d(t_mapolo *map, t_data img)
{
	int		i;
	int		j;
	t_point	ket1;
	t_point	ket2;

	i = -1;
	while (++i < map->heigth)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j != map->width - 1)
			{
				ket1.x = j;
				ket1.y = i;
				ket2.x = j + 1;
				ket2.y = i;
				draw_line(map,img, ket1, ket2);
			}
			if (i != map->heigth - 1)
			{
				ket1.x = j;
				ket1.y = i;
				ket2.x = j;
				ket2.y = i + 1;
				draw_line(map,img, ket1, ket2);
			}
		}
	}
}

int main(int ac, char **av)
{
	t_mapolo *map;

	map = malloc(sizeof(t_mapolo));
	if(!map)
		allocating();
	if (ac == 2)
	{
		first_check(av,map);
		checking(av , map);
	}
	t_data	img;
	map->alfa = 0.9;
	t_vars *vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "LOVEEEEEE!");
	img.img = mlx_new_image(vars->mlx, 1920, 1080); 
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_map2d(map , img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	closing(vars);
	mlx_hook(vars->win , 02 , 0 , escaping ,vars);
	mlx_loop(vars->mlx);
	free(vars);
	return 0;
}

