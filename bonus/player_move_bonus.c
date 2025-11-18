/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:09:42 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 15:56:51 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	change_map(t_mlx *mlx, int key)
{
	int	delx;
	int	dely;

	delx = 0;
	dely = 0;
	if (key == W)
		dely--;
	else if (key == A)
		delx--;
	else if (key == S)
		dely++;
	else if (key == D)
		delx++;
	if (mlx->map[mlx->splay.posy + dely][mlx->splay.posx + delx] != '1'
		&& (delx != 0 || dely != 0))
	{
		if (mlx->map[mlx->splay.posy + dely][mlx->splay.posx + delx] == 'C')
			mlx->nbcollect -= 1;
		mlx->map[mlx->splay.posy][mlx->splay.posx] = '0';
		mlx->map[mlx->splay.posy + dely][mlx->splay.posx + delx] = 'P';
		mlx->splay.posx += delx;
		mlx->splay.posy += dely;
		return (1);
	}
	return (0);
}

int	exit_cond(t_mlx *mlx)
{
	if (mlx->splay.posx == mlx->sexit.posx
		&& mlx->splay.posy == mlx->sexit.posy
		&& mlx->nbcollect == 0)
		return (1);
	return (0);
}
