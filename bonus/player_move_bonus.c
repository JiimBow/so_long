/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:09:42 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:21:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	change_map(t_mlx *mlx, int key, int delx, int dely)
{
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
		{
			mlx->nbcollect -= 1;
			mlx->map[mlx->splay.posy + dely][mlx->splay.posx + delx] = '0';
		}
		mlx->splay.posx += delx;
		mlx->splay.posy += dely;
		return (1);
	}
	return (0);
}

void	set_pos(t_mlx *mlx)
{
	mlx->splay.posx = pos_x(mlx->map, 'P');
	mlx->splay.posy = pos_y(mlx->map, 'P');
	mlx->sexit.posx = pos_x(mlx->map, 'E');
	mlx->sexit.posy = pos_y(mlx->map, 'E');
	mlx->slime.posx = pos_x(mlx->map, 'D');
	mlx->slime.posy = pos_y(mlx->map, 'D');
}

int	exit_cond(t_mlx *mlx)
{
	if (mlx->splay.posx == mlx->sexit.posx
		&& mlx->splay.posy == mlx->sexit.posy
		&& mlx->nbcollect == 0)
		return (1);
	if (mlx->splay.posx == mlx->slime.posx
		&& mlx->splay.posy == mlx->slime.posy)
		return (1);
	return (0);
}
