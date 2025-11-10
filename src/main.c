/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:43:57 by jodone            #+#    #+#             */
/*   Updated: 2025/11/10 18:15:26 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/jodone/Documents/42_folder/so_long/mlx/includes/mlx.h"

typedef struct
{
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	knight;
	int			x;
	int			y;
} mlx_t;

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

void update(void *param)
{
	mlx_t	*mlx = (mlx_t*)param;
	static int	x = 1;
	static int	y = 1;
	
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->knight, x, y);
	x += 120;
}

int	main(void)
{
	mlx_t	mlx;
	mlx_t	knight;

	mlx.mlx = mlx_init();

	mlx_window_create_info info = { 0 };
	info.title = "test";
	info.width = 1920;
	info.height = 1080;
	info.is_resizable = 1;
	mlx.win = mlx_new_window(mlx.mlx, &info);

	int	img_width;
	int	img_height;
	mlx_image	img = mlx_new_image_from_file(mlx.mlx, "./assets/med.png", &img_width, &img_height);
	mlx_image	kngiht = mlx_new_image_from_file(mlx.mlx, "./assets/knight.jpg", &img_height, &img_height);

	mlx_put_image_to_window(mlx.mlx, mlx.win, img, 1, 1);

	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.mlx);

	mlx_add_loop_hook(mlx.mlx, update, &mlx);
	mlx_loop(mlx.mlx);

	mlx_destroy_image(mlx.mlx, img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_context(mlx.mlx);
}