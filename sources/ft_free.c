/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:16:33 by anareval          #+#    #+#             */
/*   Updated: 2025/02/26 22:29:23 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_img(t_map *map)
{
	mlx_delete_image(map->wind, map->img->collect);
	mlx_delete_image(map->wind, map->img->empty);
	mlx_delete_image(map->wind, map->img->exit);
	mlx_delete_image(map->wind, map->img->player);
	mlx_delete_image(map->wind, map->img->wall);
	mlx_delete_image(map->wind, map->img->win);
	free(map->img);
}

void	ft_free(t_map *map)
{
	ft_free_img(map);
}
