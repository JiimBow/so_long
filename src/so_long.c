/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 13:31:07 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	key_hook(int key, void *param)
{
	t_mlx		*mlx;
	static int	nbmove = 0;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	if (change_map(mlx, key) == 1)
	{
		nbmove++;
		ft_printf("%d\n", nbmove);
	}
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

int	main(int ac, char **av)
{
	t_mlx					mlx;
	mlx_window_create_info	info;

	mlx.cont = mlx_init();
	ft_bzero(&info, sizeof(info));
	if (ac != 2)
		return (0);
	mlx.map = load_map(av[1]);
	set_pos(&mlx);
	mlx.nbcollect = count_coll(mlx.map);
	if (check_map(mlx.map, 0, 0) == 1
		|| map_is_win(av[1], mlx.splay.posx, mlx.splay.posy) == 0
		|| win_init(mlx.map, &info) == 0)
	{
		ft_printf("%s\n", "Error\nMap not good or too large");
		mlx_destroy_context(mlx.cont);
		return (0);
	}
	mlx.win = mlx_new_window(mlx.cont, &info);
	image_loader(&mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update, &mlx);
	mlx_loop(mlx.cont);
	ft_destroy(&mlx);
}
