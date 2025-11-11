/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:48:21 by jodone            #+#    #+#             */
/*   Updated: 2025/11/11 16:34:27 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

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
			break;
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
			break;
		i++;
	}
	close(fd);
	return (tab);
}

