/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:27 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:00:15 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <mlx_extended.h>


void	slime_move(t_mlx *mlx);
void	player_idle(t_mlx *mlx, int x, int y);
void	collec_idle(t_mlx *mlx, int x, int y);
void	hair_idle(t_mlx *mlx, int x, int y);
void	slime_idle(t_mlx *mlx, int x, int y);

#endif