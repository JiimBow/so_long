/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:46:14 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:34:33 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	destroy_slime(t_mlx *mlx)
{
	mlx_destroy_image(mlx->cont, mlx->slime1);
	mlx_destroy_image(mlx->cont, mlx->slime2);
	mlx_destroy_image(mlx->cont, mlx->slime3);
	mlx_destroy_image(mlx->cont, mlx->slime4);
	mlx_destroy_image(mlx->cont, mlx->slime5);
	mlx_destroy_image(mlx->cont, mlx->slime6);
	mlx_destroy_image(mlx->cont, mlx->slime7);
	mlx_destroy_image(mlx->cont, mlx->slime8);
}

void	ft_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->cont, mlx->exit);
	mlx_destroy_image(mlx->cont, mlx->collect1);
	mlx_destroy_image(mlx->cont, mlx->collect2);
	mlx_destroy_image(mlx->cont, mlx->collect3);
	mlx_destroy_image(mlx->cont, mlx->collect4);
	mlx_destroy_image(mlx->cont, mlx->collect5);
	mlx_destroy_image(mlx->cont, mlx->hair1);
	mlx_destroy_image(mlx->cont, mlx->hair2);
	mlx_destroy_image(mlx->cont, mlx->hair3);
	mlx_destroy_image(mlx->cont, mlx->hair4);
	mlx_destroy_image(mlx->cont, mlx->hair5);
	mlx_destroy_image(mlx->cont, mlx->play1);
	mlx_destroy_image(mlx->cont, mlx->play2);
	mlx_destroy_image(mlx->cont, mlx->play3);
	mlx_destroy_image(mlx->cont, mlx->play4);
	mlx_destroy_image(mlx->cont, mlx->play5);
	mlx_destroy_image(mlx->cont, mlx->play6);
	mlx_destroy_image(mlx->cont, mlx->play7);
	mlx_destroy_image(mlx->cont, mlx->play8);
	destroy_slime(mlx);
	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->floor);
	mlx_destroy_window(mlx->cont, mlx->win);
	mlx_destroy_context(mlx->cont);
}
