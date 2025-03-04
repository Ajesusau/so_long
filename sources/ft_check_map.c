/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:55:41 by anareval          #+#    #+#             */
/*   Updated: 2025/03/04 13:47:09 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fail_map(void)
{
	ft_printf("Error\nNot valid map.");
	exit(EXIT_FAILURE);
}

static void	ft_set_player_xy(t_map *map, int i, int j)
{
	map->y = i;
	map->x = j;
}

static void	ft_check_extra_objcs(char c)
{
	if ((c != '1') && (c != '0') && (c != 'P') && (c != 'E') && (c != 'C'))
		ft_fail_map();
}

void	ft_check_objcs(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_check_extra_objcs(map->map[i][j]);
			if (map->map[i][j] == 'P')
			{
				map->player++;
				ft_set_player_xy(map, i, j);
			}
			else if (map->map[i][j] == 'C')
				map->collect++;
			else if (map->map[i][j] == 'E')
				map->finish++;
			j++;
		}
		i++;
	}
	if ((map->player != 1) || (map->collect < 1) || (map->finish != 1))
		ft_fail_map();
}
