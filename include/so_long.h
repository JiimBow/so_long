/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:27 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 17:51:54 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_extended.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <libft.h>

# define W 26
# define A 4
# define S 22
# define D 7

typedef struct s_player
{
	int	posx;
	int	posy;
}	t_player;

typedef struct s_exit
{
	int	posx;
	int	posy;
}	t_exit;

typedef struct s_mlx
{
	mlx_context	cont;
	mlx_window	win;
	mlx_image	wall;
	mlx_image	floor;
	mlx_image	player;
	mlx_image	collect;
	mlx_image	exit;
	char		**map;
	t_player	splay;
	t_exit		sexit;
	int			nbcollect;
}	t_mlx;

char	**load_map(const char *file);
int		count_height(char **map);
int		count_width(char **map);
int		pos_y(char **map, char c);
int		pos_x(char **map, char c);
void	display_map(t_mlx *mlx);
int		check_map(char **map);
void	change_map(t_mlx *mlx, int key);
void	ft_destroy(void *param);
void	image_loader(t_mlx *mlx);
int		exit_cond(t_mlx *mlx);
int		count_coll(char **map);
void	win_init(char **map, mlx_window_create_info *info);

#endif