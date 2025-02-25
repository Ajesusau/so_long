/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:34:43 by anareval          #+#    #+#             */
/*   Updated: 2025/02/25 19:27:21 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_dat_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open the file");
		exit (EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	map->height = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != map->width)
		{
			ft_printf("Error: not valid map");
			exit(EXIT_FAILURE);
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}
