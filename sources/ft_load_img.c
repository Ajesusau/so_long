/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:57:37 by anareval          #+#    #+#             */
/*   Updated: 2025/02/28 09:36:47 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_load_xmp42(t_text *text)
{
	text->collect = mlx_load_png(COLLECT);
	if (text->collect == NULL)
		ft_printf("Error al cargar la imagen: %s\n", COLLECT);
	text->empty = mlx_load_png(EMPTY);
	if (text->empty == NULL)
		ft_printf("Error al cargar la imagen: %s\n", EMPTY);
	text->exit = mlx_load_png(EXIT);
	if (text->exit == NULL)
		ft_printf("Error al cargar la imagen: %s\n", EXIT);
	text->player = mlx_load_png(PLAYER);
	if (text->player == NULL)
		ft_printf("Error al cargar la imagen: %s\n", PLAYER);
	text->wall = mlx_load_png(WALL);
	if (text->wall == NULL)
		ft_printf("Error al cargar la imagen: %s\n", WALL);
	text->win = mlx_load_png(WIN);
	if (text->win == NULL)
		ft_printf("Error al cargar la imagen: %s\n", WIN);
}

void	ft_load_img(t_map *map)
{
	map->text = malloc(sizeof(t_text));
	ft_load_xmp42(map->text);
	ft_printf("Guardamos xpm en lista\n");
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
	ft_printf("Guardamos imagenes en lista\n");
}
