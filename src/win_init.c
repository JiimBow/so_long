/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:51:50 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:06:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	win_init(char **map, mlx_window_create_info *info)
{
	info->title = "so_long";
	info->width = (count_width(map)) * 100;
	info->height = count_height(map) * 100;
	info->is_resizable = 1;
	if (info->width > 1920 || info->height > 1080)
		return (0);
	return (1);
}

void	image_loader(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->floor = mlx_new_image_from_file(mlx->cont,
			"./textures/floor.jpg", &wid, &hei);
	mlx->wall = mlx_new_image_from_file(mlx->cont,
			"./textures/wall.jpg", &wid, &hei);
	mlx->player = mlx_new_image_from_file(mlx->cont,
			"./textures/player.png", &wid, &hei);
	mlx->collect = mlx_new_image_from_file(mlx->cont,
			"./textures/col1.png", &wid, &hei);
	mlx->hair1 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair1.png", &wid, &hei);
	mlx->exit = mlx_new_image_from_file(mlx->cont,
			"./textures/exit.png", &wid, &hei);
}
