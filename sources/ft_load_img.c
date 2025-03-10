/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:57:37 by anareval          #+#    #+#             */
/*   Updated: 2025/03/10 12:24:16 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fail_text(void)
{
	printf("Error\nCould not save the textures\n");
	exit (EXIT_FAILURE);
}

static void	ft_load_png(t_text *text)
{
	text->collect = mlx_load_png(COLLECT);
	if (!text->collect)
		ft_fail_text();
	text->empty = mlx_load_png(EMPTY);
	if (!text->empty)
		ft_fail_text();
	text->exit = mlx_load_png(EXIT);
	if (!text->exit)
		ft_fail_text();
	text->player = mlx_load_png(PLAYER);
	if (!text->player)
		ft_fail_text();
	text->wall = mlx_load_png(WALL);
	if (!text->wall)
		ft_fail_text();
	text->win = mlx_load_png(WIN);
	if (!text->win)
		ft_fail_text();
}

void	ft_load_img(t_map *map)
{
	map->text = malloc(sizeof(t_text));
	if (!map->text)
	{
		printf("Error\nCould not save the textures\n");
		exit (EXIT_FAILURE);
	}
	ft_load_png(map->text);
	map->img = malloc(sizeof(t_img));
	if (!map->img)
	{
		printf("Error\nCould not save the images\n");
		exit (EXIT_FAILURE);
	}
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
