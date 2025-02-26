/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:30:53 by anareval          #+#    #+#             */
/*   Updated: 2025/02/26 21:16:46 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '0')
				ft_printf("0");
			else if (map->map[i][j] == '1')
				ft_printf("1");
			else if (map->map[i][j] == 'P')
				ft_printf("P");
			else if (map->map[i][j] == 'C')
				ft_printf("c");
			else if (map->map[i][j] == 'E')
				ft_printf("E");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
