/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:04:21 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/11 01:04:23 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void args_error(void)
{
	printf("arguments aren't rigth bro");
	exit(1);
}

void	open_error(void)
{
	printf("can't open file");
	exit(1);
}

void	next_line(void)
{
	printf("you need to retry your get_next_line");
	exit(1);
}

void	allocating(void)
{
	printf("allocating falses");
	exit(1);
}
