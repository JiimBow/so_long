/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:43:57 by jodone            #+#    #+#             */
/*   Updated: 2025/11/07 13:16:20 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx.h"

void	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
}

void window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

int	main(void)
{
	mlx_context mlx = mlx_init();

	mlx_window_create_info info = { 0 };
	info.title = "test";
	info.width = 700;
	info.height = 576;	
	mlx_window win = mlx_new_window(mlx, &info);

	int	img_width;
	int	img_height;
	mlx_image img = mlx_new_image_from_file(mlx, "./assets/med.png", &img_width, &img_height);
	
	mlx_put_image_to_window(mlx, win, img, 1, 1);

	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
	
	mlx_loop(mlx);

	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
}