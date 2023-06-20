/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:04:58 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/11 01:05:00 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
 # define FDF_H

typedef struct	s_mapolo	t_mapolo;
typedef struct	s_vars		t_vars;
typedef struct	s_data		t_data;
typedef struct	s_point		t_point;

struct s_mapolo
{
	int		**arr;
	int		heigth;
	int		width;
	float	alfa;
	int		zoom;
	int		centering;
	int		downing;
};

struct	s_vars {
	void	*mlx;
	void	*win;
};

struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_point
{
	float	x;
	float	y;
	float		z;
	long long int		color;
};

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libb/libft.h"
#include "get_next_line.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>
#include  <math.h>

void	args_error(void);
void	open_error(void);
void	next_line(void);
void	allocating(void);
void	map_error(void);
void	no_digit(void);
void	width_error(int	i);
void	empty_map(void);
void	split_error(void);

int		line_checkin(char *str);
int		digit_count(char *line, t_mapolo *map);
void	get_map_width(t_mapolo *map, char **av);
void	get_map_heigth(t_mapolo *map, char **av);
void	char2d(char **str);
void	checking(char **av, t_mapolo	*map);
void	fill_struct(char *line, int	*arr);
void	allocate_memory(t_mapolo	*map);
void	first_check(char **av, t_mapolo *map);




int close_window(t_vars *vars);
void	closing(t_vars	*vars);
int	escaping(int	key, t_vars	*vars,t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	malenaa(float	x, float y);
void	define_colors( t_point *ket1, t_point *ket2);;
void	draw_line(t_mapolo *map, t_data img, t_point ket1, t_point ket2);

# endif