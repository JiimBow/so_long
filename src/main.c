/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/11 18:45:06 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_extended.h>

char	**load_map(const char *file);

typedef struct
{
	mlx_context	cont;
	mlx_window	win;
	mlx_image	wall;
	mlx_image	floor;
	mlx_image	player;
	mlx_image	collect;
	mlx_image	exit;
} mlx_t;

void	key_hook(int key, void *param)
{
	// w = 26, a = 4, s = 22, d = 7, space = 44
	static int x = 1;
	static int y = 1;
	if (key == 41)
		mlx_loop_end((mlx_context)param);	
}

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

int	count_height(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_width(char **map)
{
	int	i;
	
	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

void	display_map(mlx_t *mlx, char **map)
{
	int	x;
	int	y;
	int	w;
	int	h;

	x = 0;
	y = 0;
	h = -1;
	while (map[y])
	{
		w = 1;
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->wall, w, h, 0.1358f, 0.1358f, 0);
			else if (map[y][x] == 'P')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1358f, 0.1358f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->player, w, h - 50, 0.75f, 0.75f, 0);
			}
			else if (map[y][x] == 'C')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1358f, 0.1358f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->collect, w + 10, h, 0.60f, 0.60f, 0);
			}
			else if (map[y][x] == 'E')
			{
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1358f, 0.1358f, 0);
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->exit, w + 15, h + 15, 0.17f, 0.17f, 0);
			}
			else if (map[y][x] != '\n')
				mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->floor, w, h, 0.1358f, 0.1358f, 0);
			w += 100;
			x++;
		}
		y++;
		h += 100;
	}
}

int main(void)
{
	mlx_t mlx;
	
    mlx.cont = mlx_init();

	char	**map;
	map = load_map("./maps/tuto.ber");

	mlx_window_create_info info = { 0 };
	info.title = "test";
	info.width = (count_width(map) - 1) * 100;
	info.height = count_height(map) * 100;
	info.is_resizable = 1;
	mlx.win = mlx_new_window(mlx.cont, &info);

	int	img_width;
	int	img_height;
	mlx.floor = mlx_new_image_from_file(mlx.cont, "./textures/floor.jpg", &img_width, &img_height);
	mlx.wall = mlx_new_image_from_file(mlx.cont, "./textures/wall.jpg", &img_width, &img_height);
	mlx.player = mlx_new_image_from_file(mlx.cont, "./textures/player.png", &img_width, &img_height);
	mlx.collect = mlx_new_image_from_file(mlx.cont, "./textures/collect.png", &img_width, &img_height);
	mlx.exit = mlx_new_image_from_file(mlx.cont, "./textures/exit.png", &img_width, &img_height);

	display_map(&mlx, map);
	
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, mlx.cont);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);

	mlx_loop(mlx.cont);

	mlx_destroy_image(mlx.cont, mlx.exit);
	mlx_destroy_image(mlx.cont, mlx.collect);
	mlx_destroy_image(mlx.cont, mlx.player);
	mlx_destroy_image(mlx.cont, mlx.wall);
	mlx_destroy_image(mlx.cont, mlx.floor);
	mlx_destroy_window(mlx.cont, mlx.win);
    mlx_destroy_context(mlx.cont);
}