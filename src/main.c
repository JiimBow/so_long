/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/12 18:12:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	key_hook(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	else if (key == w)
	{
		if (change_map(mlx->map, 'w', mlx->splay.posx, mlx->splay.posy) == 1)
			mlx->splay.posy -= 1;
	}
	else if (key == a)
	{
		if (change_map(mlx->map, 'a', mlx->splay.posx, mlx->splay.posy) == 1)
			mlx->splay.posx -= 1;
	}
	else if (key == s)
	{
		if (change_map(mlx->map, 's', mlx->splay.posx, mlx->splay.posy) == 1)
			mlx->splay.posy += 1;
	}
	else if (key == d)
	{
		if (change_map(mlx->map, 'd', mlx->splay.posx, mlx->splay.posy) == 1)
			mlx->splay.posx += 1;
	}
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}

void	update(void	*param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	display_map(mlx, mlx->map);
	if (mlx->splay.posx == mlx->sexit.posx && mlx->splay.posy == mlx->sexit.posy)
		mlx_loop_end(mlx->cont);
}

int main(void)
{
	t_mlx mlx;
	
    mlx.cont = mlx_init();

	mlx.map = load_map("./maps/firstmap.ber");
	mlx.splay.posx = pos_x(mlx.map, 'P');
	mlx.splay.posy = pos_y(mlx.map, 'P');
	mlx.sexit.posx = pos_x(mlx.map, 'E');
	mlx.sexit.posy = pos_y(mlx.map, 'E');
	if (mlx.splay.posx == 0 || mlx.splay.posy == 0)
		mlx_loop_end(mlx.cont);

	mlx_window_create_info info = { 0 };
	info.title = "so_long";
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
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update, &mlx);
	mlx_loop(mlx.cont);
	ft_destroy(&mlx);
}
