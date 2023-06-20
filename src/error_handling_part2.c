/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:57:43 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/17 19:57:44 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(void)
{
	printf("giving none numeric arguments");
	exit(1);
}

void	no_digit(void)
{
	printf("none numeric arguments");
	exit(1);
}

void	width_error(int	i)
{
	printf("Error: Width - ");
	printf("[ %d ]",i);
	printf(" exceeds the standard width.");
	exit(1);
}

void	empty_map(void)
{
	printf("your map is empty");
	exit(1);
}

void	split_error(void)
{
	printf("spliting error");
	exit(1);
}
