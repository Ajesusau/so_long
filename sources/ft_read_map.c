/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:34:43 by anareval          #+#    #+#             */
/*   Updated: 2025/03/04 13:48:22 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nUnable to open the file");
		exit (EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	map->height = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != map->width)
		{
			ft_printf("Error\nNot valid map.");
			exit(EXIT_FAILURE);
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_fmalloc(void)
{
	ft_printf("Error\nCould not create the map.");
	exit(EXIT_FAILURE);
}

void	ft_save_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	map->map = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!map->map)
		ft_fmalloc();
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_fmalloc();
		map->map[i] = ft_strdup(line);
		free(line);
		if (!map->map[i])
			ft_fmalloc();
		i++;
	}
	line = NULL;
	close(fd);
}
