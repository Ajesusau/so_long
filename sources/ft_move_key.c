/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:16:50 by anareval          #+#    #+#             */
/*   Updated: 2025/03/04 12:18:03 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_key_w(t_map *map)
{
	if (map->map[map->y - 1][map->x] != '1')
	{
		map->y--;
		if (map->map[map->y][map->x] == 'C')
		{
			map->collect--;
			map->map[map->y][map->x] = '0';
		}
		if (map->collect == 0 && map->map[map->y][map->x] == 'E')
			ft_win(map);
	}
}

static void	ft_key_a(t_map *map)
{
	if (map->map[map->y][map->x - 1] != '1')
	{
		map->x--;
		if (map->map[map->y][map->x] == 'C')
		{
			map->collect--;
			map->map[map->y][map->x] = '0';
		}
		if (map->collect == 0 && map->map[map->y][map->x] == 'E')
			ft_win(map);
	}
}

static void	ft_key_s(t_map *map)
{
	if (map->map[map->y + 1][map->x] != '1')
	{
		map->y++;
		if (map->map[map->y][map->x] == 'C')
		{
			map->collect--;
			map->map[map->y][map->x] = '0';
		}
		if (map->collect == 0 && map->map[map->y][map->x] == 'E')
			ft_win(map);
	}
}

static void	ft_key_d(t_map *map)
{
	if (map->map[map->y][map->x + 1] != '1')
	{
		map->x++;
		if (map->map[map->y][map->x] == 'C')
		{
			map->collect--;
			map->map[map->y][map->x] = '0';
		}
		if (map->collect == 0 && map->map[map->y][map->x] == 'E')
			ft_win(map);
	}
}

void	ft_move_key(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_key_w(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_key_a(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_key_s(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_key_d(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(param);
}
