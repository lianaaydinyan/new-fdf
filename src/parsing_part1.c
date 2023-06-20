/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:50:59 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/17 19:51:03 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char2d(char **str)
{
	int		i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
}

void	get_map_heigth(t_mapolo *map, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_error();
	line = get_next_line(fd);
	if (!line)
		next_line();
	map->heigth = 0;
	while (line)
	{
		map->heigth++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map_width(t_mapolo *map, char **av)
{
	int		fd;
	char	*line;
	int		i;

	map->width = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_error();
	line = get_next_line(fd);
	if (!line)
		next_line();
	i = 0;
	while (line)
	{
		i = digit_count(line, map);
		line = get_next_line(fd);
		if (!line)
			break;
		if (digit_count(line, map) != i)
			width_error(i);
	}
	close(fd);
}

int digit_count(char *line, t_mapolo *map)
{
	int count;
	int i;

	count = 0;
	i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				count++;
				while (line[i + 1] >= '0' && line[i + 1] <= '9')
					i++;
			}
		}
		i++;
	}
	map->width = count;
	return (count);
}

int	line_checkin(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		{//taby stugel
			if((str[i] <= '9' && str[i] >= '0' ) || (str[i] == ' ' || str[i] == '\n' ))
				i++;
			else
				no_digit();
		}
	return (1);
}