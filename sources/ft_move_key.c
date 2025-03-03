/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:16:50 by anareval          #+#    #+#             */
/*   Updated: 2025/03/03 20:26:09 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_key_W(t_map *map)
{
	map->y -= 1;
}

static void	ft_key_A(t_map *map)
{
	map->x -= 1;
}

static void	ft_key_S(t_map *map)
{
	map->y += 1;
}
static void	ft_key_D(t_map *map)
{
	map->x += 1;
}

void	ft_move_key(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_key_W(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_key_A(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_key_S(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_key_D(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}