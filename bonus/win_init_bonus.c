/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:51:50 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 11:38:38 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

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

void	image_player(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->play1 = mlx_new_image_from_file(mlx->cont,
			"./textures/play1.png", &wid, &hei);
	mlx->play2 = mlx_new_image_from_file(mlx->cont,
			"./textures/play2.png", &wid, &hei);
	mlx->play3 = mlx_new_image_from_file(mlx->cont,
			"./textures/play3.png", &wid, &hei);
	mlx->play4 = mlx_new_image_from_file(mlx->cont,
			"./textures/play4.png", &wid, &hei);
}

void	image_loader(t_mlx *mlx)
{
	int	wid;
	int	hei;

	image_player(mlx);
	mlx->floor = mlx_new_image_from_file(mlx->cont,
			"./textures/floor.jpg", &wid, &hei);
	mlx->wall = mlx_new_image_from_file(mlx->cont,
			"./textures/wall.jpg", &wid, &hei);
	mlx->collect = mlx_new_image_from_file(mlx->cont,
			"./textures/col1.png", &wid, &hei);
	mlx->collect2 = mlx_new_image_from_file(mlx->cont,
			"./textures/col2.png", &wid, &hei);
	mlx->collect3 = mlx_new_image_from_file(mlx->cont,
			"./textures/col3.png", &wid, &hei);
	mlx->hair = mlx_new_image_from_file(mlx->cont,
			"./textures/hair.png", &wid, &hei);
	mlx->exit = mlx_new_image_from_file(mlx->cont,
			"./textures/exit.png", &wid, &hei);
}
