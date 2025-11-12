/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:27 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 14:52:50 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_extended.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <libft.h>

typedef struct s_player
{
	int	posx;
	int	posy;
} t_player;

typedef struct s_mlx
{
	mlx_context	cont;
	mlx_window	win;
	mlx_image	wall;
	mlx_image	floor;
	mlx_image	player;
	mlx_image	collect;
	mlx_image	exit;
	char**		map;
	t_player	splayer;
} t_mlx;


char	**load_map(const char *file);
int		count_height(char **map);
int		count_width(char **map);
int		player_y(char **map);
int		player_x(char **map);
void	display_map(t_mlx *mlx, char **map);
void	change_map(char **map, char c, int x, int y);

#endif