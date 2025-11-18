/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_winable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:32:57 by jodone            #+#    #+#             */
/*   Updated: 2025/11/17 12:49:22 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	map_pars(char **map, int x, int y, int nbcol)
{
	int	countcol;

	countcol = 0;
	if (map[y][x] == 'C')
		countcol++;
	if (map[y][x] == 'E')
		countcol++;
	map[y][x] = 'A';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'A')
		countcol += map_pars(map, x, y - 1, nbcol);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'A')
		countcol += map_pars(map, x + 1, y, nbcol);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'A')
		countcol += map_pars(map, x, y + 1, nbcol);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'A')
		countcol += map_pars(map, x - 1, y, nbcol);
	if (nbcol - countcol == 0)
		return (1);
	return (countcol);
}

int	map_is_win(char *file_map, int x, int y)
{
	char	**tab;
	int		nbcol;

	tab = load_map(file_map);
	nbcol = count_coll(tab) + 1;
	if (map_pars(tab, x, y, nbcol) == 1)
		return (1);
	return (0);
}
