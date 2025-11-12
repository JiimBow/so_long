/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:27 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 18:11:48 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_extended.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <libft.h>

# define w 26
# define a 4
# define s 22
# define d 7

typedef struct s_player
{
	int	posx;
	int	posy;
} t_player;

typedef struct s_exit
{
	int	posx;
	int	posy;
} t_exit;

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
	t_player	splay;
	t_exit		sexit;
	int			nbcollect;
} t_mlx;


char	**load_map(const char *file);
int		count_height(char **map);
int		count_width(char **map);
int		pos_y(char **map, char c);
int		pos_x(char **map, char c);
void	display_map(t_mlx *mlx, char **map);
int		change_map(char **map, char c, int x, int y);
void	ft_destroy(void *param);

#endif