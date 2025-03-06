/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:16:33 by anareval          #+#    #+#             */
/*   Updated: 2025/03/07 11:48:33 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_delete_text(t_map *map)
{
	mlx_delete_texture(map->text->collect);
	mlx_delete_texture(map->text->empty);
	mlx_delete_texture(map->text->exit);
	mlx_delete_texture(map->text->player);
	mlx_delete_texture(map->text->wall);
	mlx_delete_texture(map->text->win);
	free(map->text);
}

static void	ft_delete_img(t_map *map)
{
	mlx_delete_image(map->wind, map->img->collect);
	mlx_delete_image(map->wind, map->img->empty);
	mlx_delete_image(map->wind, map->img->exit);
	mlx_delete_image(map->wind, map->img->player);
	mlx_delete_image(map->wind, map->img->wall);
	mlx_delete_image(map->wind, map->img->win);
	free(map->img);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	ft_free_checker(t_mcheck *mcheck, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(mcheck->map[i]);
		i++;
	}
	free(mcheck->map);
}

void	ft_free(t_map *map)
{
	ft_free_map(map);
	ft_printf("Free map OK.\n");
	ft_delete_text(map);
	ft_printf("Free text OK.\n");
	ft_delete_img(map);
	ft_printf("Free img OK.\n");
}
