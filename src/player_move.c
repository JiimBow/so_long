/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:09:42 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 15:58:17 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	change_map(char **map, char c, int x, int y)
{
	if (c == 'w' && map[y - 1][x] != '1')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		return (1);
	}
	else if (c == 'a' && map[y][x - 1] != '1')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		return (1);
	}
	else if (c == 's' && map[y + 1][x] != '1')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		return (1);
	}
	else if (c == 'd' && map[y][x + 1] != '1')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		return (1);
	}
	return (0);
}
