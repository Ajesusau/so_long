/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:57:37 by anareval          #+#    #+#             */
/*   Updated: 2025/03/06 19:20:08 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_load_png(t_text *text)
{
	text->collect = mlx_load_png(COLLECT);
	text->empty = mlx_load_png(EMPTY);
	text->exit = mlx_load_png(EXIT);
	text->player = mlx_load_png(PLAYER);
	text->wall = mlx_load_png(WALL);
	text->win = mlx_load_png(WIN);
}

void	ft_load_img(t_map *map)
{
	map->text = malloc(sizeof(t_text));
	ft_load_png(map->text);
	map->img = malloc(sizeof(t_img));
	map->img->collect = mlx_texture_to_image
		(map->wind, map->text->collect);
	map->img->empty = mlx_texture_to_image
		(map->wind, map->text->empty);
	map->img->exit = mlx_texture_to_image
		(map->wind, map->text->exit);
	map->img->player = mlx_texture_to_image
		(map->wind, map->text->player);
	map->img->wall = mlx_texture_to_image
		(map->wind, map->text->wall);
	map->img->win = mlx_texture_to_image
		(map->wind, map->text->win);
}

void	ft_reload_img(t_map *map)
{
	if (map->img->wall)
		mlx_delete_image(map->wind, map->img->wall);
	if (map->img->empty)
		mlx_delete_image(map->wind, map->img->empty);
	if (map->img->player)
		mlx_delete_image(map->wind, map->img->player);
	if (map->img->collect)
		mlx_delete_image(map->wind, map->img->collect);
	if (map->img->exit)
		mlx_delete_image(map->wind, map->img->exit);
	if (map->img->win)
		mlx_delete_image(map->wind, map->img->win);
	map->img->collect = mlx_texture_to_image
		(map->wind, map->text->collect);
	map->img->empty = mlx_texture_to_image
		(map->wind, map->text->empty);
	map->img->exit = mlx_texture_to_image
		(map->wind, map->text->exit);
	map->img->player = mlx_texture_to_image
		(map->wind, map->text->player);
	map->img->wall = mlx_texture_to_image
		(map->wind, map->text->wall);
	map->img->win = mlx_texture_to_image
		(map->wind, map->text->win);
}
