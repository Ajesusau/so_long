/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:57:37 by anareval          #+#    #+#             */
/*   Updated: 2025/02/26 22:20:37 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_img(t_map *map)
{
	map->img = malloc(sizeof(t_img));
	if (!map->img)
		ft_fmalloc();
	map->img->collect = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(COLLECT)->texture);
	map->img->empty = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(EMPTY)->texture);
	map->img->exit = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(EXIT)->texture);
	map->img->player = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(PLAYER)->texture);
	map->img->wall = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(WALL)->texture);
	map->img->win = mlx_texture_to_image
		(map->wind, &mlx_load_xpm42(WIN)->texture);
}
