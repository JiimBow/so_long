/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:51:50 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 17:21:58 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	win_init(char **map, mlx_window_create_info *info)
{
	/*regler taille de fenetre sur max 1920 * 1080*/
	info->title = "so_long";
	info->width = (count_width(map)) * 100;
	info->height = count_height(map) * 100;
	info->is_resizable = 1;
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
			"./textures/collect.png", &wid, &hei);
	mlx->exit = mlx_new_image_from_file(mlx->cont,
			"./textures/exit.png", &wid, &hei);
}
