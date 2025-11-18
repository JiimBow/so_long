/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:46:14 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 17:52:19 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	ft_destroy(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_image(mlx->cont, mlx->exit);
	mlx_destroy_image(mlx->cont, mlx->collect);
	mlx_destroy_image(mlx->cont, mlx->collect2);
	mlx_destroy_image(mlx->cont, mlx->collect3);
	mlx_destroy_image(mlx->cont, mlx->hair);
	mlx_destroy_image(mlx->cont, mlx->play1);
	mlx_destroy_image(mlx->cont, mlx->play2);
	mlx_destroy_image(mlx->cont, mlx->play3);
	mlx_destroy_image(mlx->cont, mlx->play4);
	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->floor);
	mlx_destroy_window(mlx->cont, mlx->win);
	mlx_destroy_context(mlx->cont);
}
