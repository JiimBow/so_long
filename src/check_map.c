/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:25:31 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 17:40:29 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	count_coll(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_item(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 1;
	count = 0;
	if (count_coll(map) != 0)
		count++;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'P' || map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count == 3)
		return (1);
	return (0);
}

int	check_map(char **map, int x, int y)
{
	while (map[0][x] && map[0][x] != '\n')
	{
		if (map[0][x] != '1')
			return (1);
		x++;
	}
	x -= 1;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x] != '1')
			return (1);
		y++;
	}
	y -= 1;
	x = 0;
	while (map[y][x] && map[y][x] != '\n')
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	if (check_item(map) == 0)
		return (1);
	return (0);
}

int	check_game(t_mlx *mlx, mlx_window_create_info *info, char *av1)
{
	if (check_map(mlx->map, 0, 0) == 1
		|| map_is_win(av1, mlx->splay.posx, mlx->splay.posy) == 0
		|| win_init(mlx->map, info) == 0)
	{
		ft_printf("%s\n", "Error\nMap not good or too large");
		mlx_destroy_context(mlx->cont);
		return (1);
	}
	return (0);
}
