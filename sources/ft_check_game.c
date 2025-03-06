/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:29:19 by anareval          #+#    #+#             */
/*   Updated: 2025/03/06 20:49:27 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_limits(t_map *map)
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

static void	ft_charger_checker(t_mcheck *mcheck, t_map *map)
{
	int	i;

	i = 0;
	mcheck->map = (char **)malloc((map->height + 1) * sizeof(char *));
	while (i < map->height)
	{
		mcheck->map[i] = ft_strdup(map->map[i]);
		i++;
	}
	mcheck->collect = map->collect;
	mcheck->finish = map->finish;
	mcheck->x = map->x;
	mcheck->y = map->y;
}

static void	ft_free_checker(t_mcheck *mcheck, t_map *map)
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

/*static void	ft_flood_fill(t_mcheck *mcheck)
{
}*/

void	ft_check_game(t_map *map)
{
	t_mcheck	mcheck;

	ft_charger_checker(&mcheck, map);
	ft_free_checker(&mcheck, map);
}
