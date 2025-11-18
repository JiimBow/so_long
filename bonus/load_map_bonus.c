/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:48:21 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 14:59:33 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

char	**load_map(const char *file)
{
	int		fd;
	char	**tab;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		if (get_next_line(fd) == NULL)
			break ;
		i++;
	}
	tab = malloc(((i + 1) * sizeof(char *)));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (tab);
}

void	set_pos(t_mlx *mlx)
{
	mlx->splay.posx = pos_x(mlx->map, 'P');
	mlx->splay.posy = pos_y(mlx->map, 'P');
	mlx->sexit.posx = pos_x(mlx->map, 'E');
	mlx->sexit.posy = pos_y(mlx->map, 'E');
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
	return (i - 1);
}
