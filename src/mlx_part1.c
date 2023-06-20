#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	closing(t_vars	*vars)
{
	mlx_hook(vars->win, 17, 0, close_window, vars);
}

int	escaping(int	key, t_vars	*vars,t_data *img)
{
	(void)img;
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
		// mlx_destroy_image()
	return (0);
}

//esc-i hamar grel
