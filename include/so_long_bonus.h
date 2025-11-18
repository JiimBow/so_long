/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:27 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:36:31 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int			posx;
	int			posy;
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
	mlx_image	play1;
	mlx_image	play2;
	mlx_image	play3;
	mlx_image	play4;
	mlx_image	play5;
	mlx_image	play6;
	mlx_image	play7;
	mlx_image	play8;
	mlx_image	collect1;
	mlx_image	collect2;
	mlx_image	collect3;
	mlx_image	collect4;
	mlx_image	collect5;
	mlx_image	hair1;
	mlx_image	hair2;
	mlx_image	hair3;
	mlx_image	hair4;
	mlx_image	hair5;
	mlx_image	slime1;
	mlx_image	slime2;
	mlx_image	slime3;
	mlx_image	slime4;
	mlx_image	slime5;
	mlx_image	slime6;
	mlx_image	slime7;
	mlx_image	slime8;
	mlx_image	exit;
	char		**map;
	t_player	splay;
	t_exit		sexit;
	int			nbcollect;
	int			frame;
	int			nbmove;
}	t_mlx;

char	**load_map(const char *file);
void	set_pos(t_mlx *mlx);
int		count_height(char **map);
int		count_width(char **map);
int		pos_y(char **map, char c);
int		pos_x(char **map, char c);
void	display_map(t_mlx *mlx, int x, int y);
int		check_map(char **map, int x, int y);
int		change_map(t_mlx *mlx, int key);
void	ft_destroy(t_mlx *mlx);
void	image_loader(t_mlx *mlx);
int		exit_cond(t_mlx *mlx);
int		count_coll(char **map);
int		map_is_win(char *file_map, int x, int y);
int		win_init(char **map, mlx_window_create_info *info);
int		check_game(t_mlx *mlx, mlx_window_create_info *info, char *av1);
void	player_idle(t_mlx *mlx, int x, int y);
void	collec_idle(t_mlx *mlx, int x, int y);
void	hair_idle(t_mlx *mlx, int x, int y);
void	slime_idle(t_mlx *mlx, int x, int y);

#endif