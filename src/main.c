/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 15:16:39 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	key_hook(int key, void *param)
{
	// w = 26, a = 4, s = 22, d = 7, space = 44
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	else if (key == 26)
	{
		mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
		change_map(mlx->map, 'w', mlx->splayer.posx, mlx->splayer.posy);
		display_map(mlx, mlx->map);
	}
	else if (key == 4)
	{
		mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
		change_map(mlx->map, 'a', mlx->splayer.posx, mlx->splayer.posy);
		display_map(mlx, mlx->map);
	}
	else if (key == 22)
	{
		mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
		change_map(mlx->map, 's', mlx->splayer.posx, mlx->splayer.posy);
		display_map(mlx, mlx->map);
	}
	else if (key == 7)
	{
		mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
		change_map(mlx->map, 'd', mlx->splayer.posx, mlx->splayer.posy);
		display_map(mlx, mlx->map);
	}
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}

// int	update(void	*param)
// {
// 	t_mlx *mlx;

// 	mlx = (t_mlx *)param;
// 	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
// 	display_map(mlx, mlx->map);
// }

int main(void)
{
	t_mlx mlx;
	
    mlx.cont = mlx_init();

	mlx.map = load_map("./maps/tuto.ber");
	mlx.splayer.posx = player_x(mlx.map);
	mlx.splayer.posy = player_y(mlx.map);
	if (mlx.splayer.posx == 0 || mlx.splayer.posy == 0)
		mlx_loop_end(mlx.cont);

	mlx_window_create_info info = { 0 };
	info.title = "test";
	// regler taille de fenetre sur max 1920 * 1080
	info.width = (count_width(mlx.map) - 1) * 100;
	info.height = count_height(mlx.map) * 100;
	info.is_resizable = 1;
	mlx.win = mlx_new_window(mlx.cont, &info);

	int	img_width;
	int	img_height;
	mlx.floor = mlx_new_image_from_file(mlx.cont, "./textures/floor.jpg", &img_width, &img_height);
	mlx.wall = mlx_new_image_from_file(mlx.cont, "./textures/wall.jpg", &img_width, &img_height);
	mlx.player = mlx_new_image_from_file(mlx.cont, "./textures/player.png", &img_width, &img_height);
	mlx.collect = mlx_new_image_from_file(mlx.cont, "./textures/collect.png", &img_width, &img_height);
	mlx.exit = mlx_new_image_from_file(mlx.cont, "./textures/exit.png", &img_width, &img_height);

	display_map(&mlx, mlx.map);
	
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);

	mlx_loop(mlx.cont);

	mlx_destroy_image(mlx.cont, mlx.exit);
	mlx_destroy_image(mlx.cont, mlx.collect);
	mlx_destroy_image(mlx.cont, mlx.player);
	mlx_destroy_image(mlx.cont, mlx.wall);
	mlx_destroy_image(mlx.cont, mlx.floor);
	mlx_destroy_window(mlx.cont, mlx.win);
    mlx_destroy_context(mlx.cont);
}