/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:46:14 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:07:04 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <so_long_bonus.h>

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

void	destroy_slime(t_mlx *mlx)
{
	mlx_destroy_image(mlx->cont, mlx->slime.slime1);
	mlx_destroy_image(mlx->cont, mlx->slime.slime2);
	mlx_destroy_image(mlx->cont, mlx->slime.slime3);
	mlx_destroy_image(mlx->cont, mlx->slime.slime4);
	mlx_destroy_image(mlx->cont, mlx->slime.slime5);
	mlx_destroy_image(mlx->cont, mlx->slime.slime6);
	mlx_destroy_image(mlx->cont, mlx->slime.slime7);
	mlx_destroy_image(mlx->cont, mlx->slime.slime8);
}

void	ft_destroy(t_mlx *mlx)
{
	ft_free(mlx->map);
	mlx_destroy_image(mlx->cont, mlx->exit);
	mlx_destroy_image(mlx->cont, mlx->coll.collect1);
	mlx_destroy_image(mlx->cont, mlx->coll.collect2);
	mlx_destroy_image(mlx->cont, mlx->coll.collect3);
	mlx_destroy_image(mlx->cont, mlx->coll.collect4);
	mlx_destroy_image(mlx->cont, mlx->coll.collect5);
	mlx_destroy_image(mlx->cont, mlx->coll.hair1);
	mlx_destroy_image(mlx->cont, mlx->coll.hair2);
	mlx_destroy_image(mlx->cont, mlx->coll.hair3);
	mlx_destroy_image(mlx->cont, mlx->coll.hair4);
	mlx_destroy_image(mlx->cont, mlx->coll.hair5);
	mlx_destroy_image(mlx->cont, mlx->splay.play1);
	mlx_destroy_image(mlx->cont, mlx->splay.play2);
	mlx_destroy_image(mlx->cont, mlx->splay.play3);
	mlx_destroy_image(mlx->cont, mlx->splay.play4);
	mlx_destroy_image(mlx->cont, mlx->splay.play5);
	mlx_destroy_image(mlx->cont, mlx->splay.play6);
	mlx_destroy_image(mlx->cont, mlx->splay.play7);
	mlx_destroy_image(mlx->cont, mlx->splay.play8);
	destroy_slime(mlx);
	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->floor);
	mlx_destroy_window(mlx->cont, mlx->win);
	mlx_destroy_context(mlx->cont);
}
