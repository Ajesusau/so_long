/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:30:53 by anareval          #+#    #+#             */
/*   Updated: 2025/03/03 12:46:45 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				mlx_image_to_window(map->wind, map->img->wall, j * 50, i * 50);
			else
				mlx_image_to_window(map->wind, map->img->empty, j * 50, i * 50);
			if (map->map[i][j] == 'P')
				mlx_image_to_window(map->wind, map->img->player, j * 50, i * 50);
			else if (map->map[i][j] == 'C')
				mlx_image_to_window(map->wind, map->img->collect, j * 50, i * 50);
			else if (map->map[i][j] == 'E')
				mlx_image_to_window(map->wind, map->img->exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
