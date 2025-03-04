/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:30:53 by anareval          #+#    #+#             */
/*   Updated: 2025/03/04 14:17:35 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_player(t_map *map, int i, int j)
{
	mlx_image_to_window(map->wind, map->img->player, j * 50, i * 50);
}

static void	ft_put_collect(t_map *map, int i, int j)
{
	mlx_image_to_window(map->wind, map->img->collect, j * 50, i * 50);
}

static void	ft_put_exit(t_map *map, int i, int j)
{
	mlx_image_to_window(map->wind, map->img->exit, j * 50, i * 50);
}

void	ft_rdraw_map(t_map *map)
{
	ft_draw_map(map);
}

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
			if (map->map[i][j] == 'C')
				ft_put_collect(map, i, j);
			else if (map->map[i][j] == 'E')
				ft_put_exit(map, i, j);
			j++;
		}
		i++;
	}
	ft_put_player(map, map->y, map->x);
}
