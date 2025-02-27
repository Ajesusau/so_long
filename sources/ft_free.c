/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:16:33 by anareval          #+#    #+#             */
/*   Updated: 2025/02/27 14:24:13 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void ft_free_xmp42(t_map *map)
{
	mlx_delete_xpm42(map->text->collect);
	mlx_delete_xpm42(map->text->empty);
	mlx_delete_xpm42(map->text->exit);
	mlx_delete_xpm42(map->text->player);
	mlx_delete_xpm42(map->text->wall);
	mlx_delete_xpm42(map->text->win);
}

static void	ft_free_img(t_map *map)
{
	mlx_delete_image(map->wind, map->img->collect);
	mlx_delete_image(map->wind, map->img->empty);
	mlx_delete_image(map->wind, map->img->exit);
	mlx_delete_image(map->wind, map->img->player);
	mlx_delete_image(map->wind, map->img->wall);
	mlx_delete_image(map->wind, map->img->win);
}

static void ft_free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
}

void	ft_free(t_map *map)
{
	ft_free_map(map);
	ft_free_img(map);
	ft_free_xmp42(map);
}
