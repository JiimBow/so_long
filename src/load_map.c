/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:48:21 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 17:43:32 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
