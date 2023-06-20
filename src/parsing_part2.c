/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:51:08 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/17 19:51:10 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_check(char **av, t_mapolo *map)
{
	get_map_width(map, av);
	get_map_heigth(map, av);
	if(map->heigth < 1 && map->width < 1)
		empty_map();
}


void	allocate_memory(t_mapolo	*map)
{
	int	i;

	i = 0;
	map->arr = (int **)malloc(sizeof(int *) * map->heigth);
	if (!map->arr)
		allocating();
	while (i <= map->heigth)
	{
		map->arr[i] = (int *)malloc(sizeof(int) * map->width);
		if (!map->arr[i])
			allocating();
		i++;
	}
}

void	fill_struct(char *line, int	*arr)
{
	int		j;
	char	**split;

	j = -1;
	split = ft_split(line, ' ');
	if (!split)
		split_error();
	while (split[++j])
	{
		arr[j] = ft_atoi(split[j]);
		free(split[j]);
	}
	free(split);
	
}

void	checking(char **av, t_mapolo	*map)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	allocate_memory(map);
	fd = open(av[1] , O_RDONLY);
	if (fd == -1)
		open_error();
	while (++i < map->heigth)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if(line_checkin(line))
			fill_struct(line,map->arr[i]);
	}
}
