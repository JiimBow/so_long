/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:51:50 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:24:02 by jodone           ###   ########.fr       */
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

void	image_collect(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->collect1 = mlx_new_image_from_file(mlx->cont,
			"./textures/col1.png", &wid, &hei);
	mlx->collect2 = mlx_new_image_from_file(mlx->cont,
			"./textures/col2.png", &wid, &hei);
	mlx->collect3 = mlx_new_image_from_file(mlx->cont,
			"./textures/col3.png", &wid, &hei);
	mlx->collect4 = mlx_new_image_from_file(mlx->cont,
			"./textures/col4.png", &wid, &hei);
	mlx->collect5 = mlx_new_image_from_file(mlx->cont,
			"./textures/col5.png", &wid, &hei);
	mlx->hair1 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair1.png", &wid, &hei);
	mlx->hair2 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair2.png", &wid, &hei);
	mlx->hair3 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair3.png", &wid, &hei);
	mlx->hair4 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair4.png", &wid, &hei);
	mlx->hair5 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair5.png", &wid, &hei);
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
	mlx->play5 = mlx_new_image_from_file(mlx->cont,
			"./textures/play5.png", &wid, &hei);
	mlx->play6 = mlx_new_image_from_file(mlx->cont,
			"./textures/play6.png", &wid, &hei);
	mlx->play7 = mlx_new_image_from_file(mlx->cont,
			"./textures/play7.png", &wid, &hei);
	mlx->play8 = mlx_new_image_from_file(mlx->cont,
			"./textures/play8.png", &wid, &hei);
}

void	image_slime(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->slime1 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime1.png", &wid, &hei);
	mlx->slime2 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime2.png", &wid, &hei);
	mlx->slime3 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime3.png", &wid, &hei);
	mlx->slime4 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime4.png", &wid, &hei);
	mlx->slime5 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime5.png", &wid, &hei);
	mlx->slime6 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime6.png", &wid, &hei);
	mlx->slime7 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime7.png", &wid, &hei);
	mlx->slime8 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime8.png", &wid, &hei);
}

void	image_loader(t_mlx *mlx)
{
	int	wid;
	int	hei;

	image_player(mlx);
	image_collect(mlx);
	image_slime(mlx);
	mlx->floor = mlx_new_image_from_file(mlx->cont,
			"./textures/floor.jpg", &wid, &hei);
	mlx->wall = mlx_new_image_from_file(mlx->cont,
			"./textures/wall.jpg", &wid, &hei);
	mlx->exit = mlx_new_image_from_file(mlx->cont,
			"./textures/exit.png", &wid, &hei);
}
