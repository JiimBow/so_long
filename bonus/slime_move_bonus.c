/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:19 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:10:33 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <sys/time.h>

int	random_move(int possible_direction)
{
	struct timeval	tv;
	unsigned long	seed;

	gettimeofday(&tv, NULL);
	seed = (unsigned long)(tv.tv_sec);
	return (seed % (possible_direction + 1));
}

int	slime_possible_dir(t_mlx *mlx, int tab_direction[4])
{
	int	count;

	count = 0;
	if (mlx->map[mlx->slime.posy - 1][mlx->slime.posx] != '1')
	{
		tab_direction[count] = W;
		count++;
	}
	if (mlx->map[mlx->slime.posy][mlx->slime.posx - 1] != '1')
	{
		tab_direction[count] = A;
		count++;
	}
	if (mlx->map[mlx->slime.posy + 1][mlx->slime.posx] != '1')
	{
		tab_direction[count] = S;
		count++;
	}
	if (mlx->map[mlx->slime.posy][mlx->slime.posx + 1] != '1')
	{
		tab_direction[count] = D;
		count++;
	}
	return (count);
}

void	slime_move(t_mlx *mlx)
{
	int		count;
	int		dir;
	int		tab_direction[4];

	count = slime_possible_dir(mlx, tab_direction);
	if (count != 0)
	{
		dir = random_move(count - 1);
		if (tab_direction[dir] == W)
			mlx->slime.posy -= 1;
		if (tab_direction[dir] == A)
			mlx->slime.posx -= 1;
		if (tab_direction[dir] == S)
			mlx->slime.posy += 1;
		if (tab_direction[dir] == D)
			mlx->slime.posx += 1;
	}
}
