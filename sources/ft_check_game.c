/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:29:19 by anareval          #+#    #+#             */
/*   Updated: 2025/03/06 23:18:17 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_limits(t_map *map)
{
	int	i;

	i = 0;
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
	if (!mcheck->map)
	{
		printf("Error\nCould not create the check map\n");
		exit (EXIT_FAILURE);
	}
	while (i < map->height)
	{
		mcheck->map[i] = ft_strdup(map->map[i]);
		i++;
	}
	mcheck->collect = map->collect;
	mcheck->finish = map->finish;
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

static void	ft_flood_fill(t_mcheck *mcheck, int y, int x)
{
	if (mcheck->map[y][x] == 'C')
		mcheck->collect--;
	if (mcheck->map[y][x] == 'E')
		mcheck->finish--;
	if (mcheck->map[y][x] != '1' && mcheck->map[y][x] != 'X')
	{
		mcheck->map[y][x] = 'X';
		ft_flood_fill(mcheck, y - 1, x);
		ft_flood_fill(mcheck, y + 1, x);
		ft_flood_fill(mcheck, y, x - 1);
		ft_flood_fill(mcheck, y, x + 1);
	}
}

void	ft_check_game(t_map *map)
{
	t_mcheck	mcheck;

	ft_charger_checker(&mcheck, map);
	ft_flood_fill(&mcheck, map->y, map->x);
	if (mcheck.collect > 0 && mcheck.finish > 0)
	{
		ft_printf("Error\nNot valid map.");
		exit (EXIT_FAILURE);
	}
	ft_free_checker(&mcheck, map);
}
