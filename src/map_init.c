/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:27:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 14:03:00 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_map(t_mlx *mlx, char **map)
{
	// calculer la conversion des dimensions pour pouvoir changer d'image quqnd je veux
	int	x;
	int	y;
	int	w;
	int	h;

	x = 0;
	y = 0;
	h = 1;
	while (map[y])
	{
		w = 1;
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->wall, w, h, 0.1358f, 0.1358f, 0);
			else if (map[y][x] == 'P')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1262f, 0.1584f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->player, w, h - 50, 0.75f, 0.75f, 0);
			}
			else if (map[y][x] == 'C')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1262f, 0.1584f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->collect, w + 10, h, 0.60f, 0.60f, 0);
			}
			else if (map[y][x] == 'E')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1262f, 0.1584f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->exit, w + 15, h + 15, 0.17f, 0.17f, 0);
			}
			else if (map[y][x] == '0')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1262f, 0.1584f, 0);
			w += 100;
			x++;
		}
		y++;
		h += 100;
	}
}
