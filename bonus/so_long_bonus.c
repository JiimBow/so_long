/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:22 by jodone            #+#    #+#             */
/*   Updated: 2025/11/18 16:36:39 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	key_hook(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	if (change_map(mlx, key) == 1)
		mlx->nbmove++;
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
	mlx->frame++;
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	display_map(mlx, 0, 0);
	mlx_string_put(mlx->cont, mlx->win, 20, 50,
		(mlx_color){.rgba = 0xFFFFFFFF}, ft_itoa(mlx->nbmove));
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
	set_pos(&mlx);
	mlx.nbcollect = count_coll(mlx.map);
	if (check_game(&mlx, &info, av[1]) == 1)
		return (0);
	mlx.win = mlx_new_window(mlx.cont, &info);
	image_loader(&mlx);
	mlx_set_font_scale(mlx.cont, "./textures/font.ttf", 50);
	mlx_set_fps_goal(mlx.cont, 60);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update, &mlx);
	mlx_loop(mlx.cont);
	ft_destroy(&mlx);
}
