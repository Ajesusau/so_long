/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:19 by anareval          #+#    #+#             */
/*   Updated: 2025/03/03 17:11:49 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_ini_dat(t_map *map, char *argv[])
{
	map->x = 0;
	map->y = 0;
	map->player = 0;
	map->collect = 0;
	map->finish = 0;
	ft_save_map(map, argv[1]);
	ft_printf("Map Read.\n");
	ft_load_img(map);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		ft_read_map(&map, argv[1]);
		map.wind = mlx_init(map.width * 50, map.height * 50, "42so_long", true);
		ft_ini_dat(&map, argv);
		ft_printf("Game started...\n");
		ft_check_objcs(&map);
		ft_draw_map(&map);
		ft_printf("Img saved OK.\n");
		mlx_loop(map.wind);
		ft_printf("Loop OK.\n");
		mlx_terminate(map.wind);
		ft_printf("Terminate OK.\n");
		ft_free(&map);
		ft_printf("Free OK.\n");
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Invalid number of arguments.\n");
		return (EXIT_FAILURE);
	}
}
