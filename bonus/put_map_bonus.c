/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:27:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:07:42 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <so_long_bonus.h>

void	put_map_floor(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' || map[y][x] != '\n' || map[y][x] != '\0')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
					mlx->floor, (100 * x) + 1, (100 * y) + 1, 0.1262f,
					0.1584f, 0);
			x++;
		}
		y++;
	}
}

void	put_map_wall(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
					mlx->wall, (100 * x) + 1, (100 * y) + 1, 0.1358f,
					0.1358f, 0);
			x++;
		}
		y++;
	}
}

void	display_map(t_mlx *mlx, int x, int y)
{
	put_map_floor(mlx, mlx->map);
	put_map_wall(mlx, mlx->map);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
		mlx->exit, (100 * mlx->sexit.posx) + 16,
		(100 * mlx->sexit.posy) + 16, 0.17f, 0.17f, 0);
	player_idle(mlx, mlx->splay.posx, mlx->splay.posy);
	if (mlx->slime.posx != 0 && mlx->slime.posy != 0)
		slime_idle(mlx, mlx->slime.posx, mlx->slime.posy);
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'C')
			{
				collec_idle(mlx, x, y);
				hair_idle(mlx, x, y);
			}
			x++;
		}
		y++;
	}
}
