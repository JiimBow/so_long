/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/19 17:58:58 by jodone           ###   ########.fr       */
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
	if (change_map(mlx, key, 0, 0) == 1)
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
	display_map(mlx, 0, 0);
	if (exit_cond(mlx))
		mlx_loop_end(mlx->cont);
}

int	main(int ac, char **av)
{
	t_mlx					mlx;
	mlx_window_create_info	info;

	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&info, sizeof(info));
	mlx.cont = mlx_init();
	if (ac != 2)
		return (0);
	mlx.map = load_map(av[1]);
	if (!mlx.map)
		return (0);
	if (check_game(&mlx, &info, av[1]) == 1)
	{
		ft_free(mlx.map);
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
