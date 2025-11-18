/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:27:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 17:51:58 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	collec_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 24 < 6)
	{
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect, (100 * x) + 11, (100 * y) + 1, 1, 1, 0);
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair, (100 * x) + 39, (100 * y) + 5, 0.5f, 0.5f, 0);
	}
	else if (mlx->frame % 24 < 12)
	{
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect2, (100 * x) + 11, (100 * y) + 1, 1, 1, 0);
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair, (100 * x) + 39, (100 * y) + 5, 0.5f, 0.5f, 0);
	}
	else
	{
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect3, (100 * x) + 11, (100 * y) + 1, 1, 1, 0);
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair, (100 * x) + 39, (100 * y) + 5, 0.5f, 0.5f, 0);
	}
}

void	player_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 24 < 6)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play1, (100 * x) + 25, (100 * y) + 13, 0.3f, 0.3f, 0);
	else if (mlx->frame % 64 < 12)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play2, (100 * x) + 25, (100 * y) + 13, 0.3f, 0.3f, 0);
	else if (mlx->frame % 64 < 18)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play3, (100 * x) + 25, (100 * y) + 13, 0.3f, 0.3f, 0);
	else
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play4, (100 * x) + 25, (100 * y) + 13, 0.3f, 0.3f, 0);
}

void	display_map(t_mlx *mlx)
{
	int			x;
	int			y;

	y = 0;
	put_map_floor(mlx, mlx->map);
	put_map_wall(mlx, mlx->map);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
		mlx->exit, (100 * mlx->sexit.posx) + 16,
		(100 * mlx->sexit.posy) + 16, 0.17f, 0.17f, 0);
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'P')
				player_idle(mlx, x, y);
			else if (mlx->map[y][x] == 'C')
				collec_idle(mlx, x, y);
			x++;
		}
		y++;
	}
}
