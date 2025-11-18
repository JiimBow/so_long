/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_frame_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:38:59 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:30:22 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	hair_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 25 < 5)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair1, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 10)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair2, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 15)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair3, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 20)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair4, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->hair5, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
}

void	collec_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 25 < 10)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect1, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 10)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect2, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 15)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect3, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else if (mlx->frame % 25 < 20)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect4, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
	else
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->collect5, (100 * x) - 18, (100 * y) - 15, 1.8, 1.8, 0);
}

void	player_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 64 < 8)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play1, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 16)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play2, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 24)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play3, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 32)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play4, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 40)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play5, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 48)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play6, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else if (mlx->frame % 64 < 56)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play7, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
	else
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->play8, (100 * x) - 64, (100 * y) - 60, 2, 2, 0);
}

void	slime_idle(t_mlx *mlx, int x, int y)
{
	if (mlx->frame % 64 < 8)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime1, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 16)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime2, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 24)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime3, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 32)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime4, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 40)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime5, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 48)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime6, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else if (mlx->frame % 64 < 56)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime7, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
	else
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->slime8, (100 * x) + 15, (100 * y) + 20, 2.5, 2.5, 0);
}
