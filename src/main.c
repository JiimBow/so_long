/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 18:01:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	change_map(mlx, key);
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}

void	update(void	*param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	display_map(mlx);
	if (exit_cond(mlx))
		mlx_loop_end(mlx->cont);
}

int	main(void)
{
	t_mlx					mlx;
	mlx_window_create_info	info = {0};

	mlx.cont = mlx_init();
	mlx.map = load_map("./maps/firstmap.ber");
	// if (check_map(mlx.map))
	// 	mlx_destroy_context(mlx.cont);
	mlx.splay.posx = pos_x(mlx.map, 'P');
	mlx.splay.posy = pos_y(mlx.map, 'P');
	mlx.sexit.posx = pos_x(mlx.map, 'E');
	mlx.sexit.posy = pos_y(mlx.map, 'E');
	if (mlx.splay.posx == 0 || mlx.splay.posy == 0)
		mlx_loop_end(mlx.cont);
	mlx.nbcollect = count_coll(mlx.map);
	win_init(mlx.map, &info);
	mlx.win = mlx_new_window(mlx.cont, &info);
	image_loader(&mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update, &mlx);
	mlx_loop(mlx.cont);
	ft_destroy(&mlx);
}
