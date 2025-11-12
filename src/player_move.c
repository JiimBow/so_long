/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:09:42 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 15:06:46 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	change_map(char **map, char c, int x, int y)
{
	ft_printf("%d\n%d\n", x, y);
	if (c == 'w' && map[y - 1][x] != '1')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
	}
	else if (c == 'a' && map[y][x - 1] != '1')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
	}
	else if (c == 's' && map[y + 1][x] != '1')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
	}
	else if (c == 'd' && map[y][x + 1] != '1')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
	}
}
