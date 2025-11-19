/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:46:14 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:16:14 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

void	ft_destroy(t_mlx *mlx)
{
	ft_free(mlx->map);
	mlx_destroy_image(mlx->cont, mlx->exit);
	mlx_destroy_image(mlx->cont, mlx->collect);
	mlx_destroy_image(mlx->cont, mlx->hair1);
	mlx_destroy_image(mlx->cont, mlx->player);
	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->floor);
	mlx_destroy_window(mlx->cont, mlx->win);
	mlx_destroy_context(mlx->cont);
}
