/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:29:19 by anareval          #+#    #+#             */
/*   Updated: 2025/03/06 20:01:56 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_map_limits(t_map *map)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
		{
			printf("Error\nMap outline bad\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
		{
			printf("Error\nMap outline bad\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
