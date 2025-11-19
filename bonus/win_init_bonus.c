/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:51:50 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:08:28 by jodone           ###   ########.fr       */
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

void	image_collect(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->coll.collect1 = mlx_new_image_from_file(mlx->cont,
			"./textures/col1.png", &wid, &hei);
	mlx->coll.collect2 = mlx_new_image_from_file(mlx->cont,
			"./textures/col2.png", &wid, &hei);
	mlx->coll.collect3 = mlx_new_image_from_file(mlx->cont,
			"./textures/col3.png", &wid, &hei);
	mlx->coll.collect4 = mlx_new_image_from_file(mlx->cont,
			"./textures/col4.png", &wid, &hei);
	mlx->coll.collect5 = mlx_new_image_from_file(mlx->cont,
			"./textures/col5.png", &wid, &hei);
	mlx->coll.hair1 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair1.png", &wid, &hei);
	mlx->coll.hair2 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair2.png", &wid, &hei);
	mlx->coll.hair3 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair3.png", &wid, &hei);
	mlx->coll.hair4 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair4.png", &wid, &hei);
	mlx->coll.hair5 = mlx_new_image_from_file(mlx->cont,
			"./textures/hair5.png", &wid, &hei);
}

void	image_player(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->splay.play1 = mlx_new_image_from_file(mlx->cont,
			"./textures/play1.png", &wid, &hei);
	mlx->splay.play2 = mlx_new_image_from_file(mlx->cont,
			"./textures/play2.png", &wid, &hei);
	mlx->splay.play3 = mlx_new_image_from_file(mlx->cont,
			"./textures/play3.png", &wid, &hei);
	mlx->splay.play4 = mlx_new_image_from_file(mlx->cont,
			"./textures/play4.png", &wid, &hei);
	mlx->splay.play5 = mlx_new_image_from_file(mlx->cont,
			"./textures/play5.png", &wid, &hei);
	mlx->splay.play6 = mlx_new_image_from_file(mlx->cont,
			"./textures/play6.png", &wid, &hei);
	mlx->splay.play7 = mlx_new_image_from_file(mlx->cont,
			"./textures/play7.png", &wid, &hei);
	mlx->splay.play8 = mlx_new_image_from_file(mlx->cont,
			"./textures/play8.png", &wid, &hei);
}

void	image_slime(t_mlx *mlx)
{
	int	wid;
	int	hei;

	mlx->slime.slime1 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime1.png", &wid, &hei);
	mlx->slime.slime2 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime2.png", &wid, &hei);
	mlx->slime.slime3 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime3.png", &wid, &hei);
	mlx->slime.slime4 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime4.png", &wid, &hei);
	mlx->slime.slime5 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime5.png", &wid, &hei);
	mlx->slime.slime6 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime6.png", &wid, &hei);
	mlx->slime.slime7 = mlx_new_image_from_file(mlx->cont,
			"./textures/slime7.png", &wid, &hei);
	mlx->slime.slime8 = mlx_new_image_from_file(mlx->cont,
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
