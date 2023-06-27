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
	if (map->heigth < 1 && map->width < 1)
		empty_map();
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
	int		j;

	j = -1;
	map->arr = (int **)malloc(sizeof(int *) * map->heigth);
	if (!map->arr)
		allocating();
	while (++j < map->heigth)
	{
		map->arr[j] = (int *)malloc(sizeof(int) * map->width);
		if(!map->arr[j])
			allocating();
	}
	j = -1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_error();
	while (++j < map->heigth)
	{
		line = get_next_line(fd);
		if (line_is_empthy(line))
		{
			printf("empthy\n");
			exit(1);
		}
		if (!line)
			break ;
		if (line_checkin(line))
			fill_struct(line, map->arr[j]);
		free(line);
		// system("leaks fdf");
	}
	close(fd);
}
