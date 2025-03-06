/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:19 by anareval          #+#    #+#             */
/*   Updated: 2025/03/07 11:36:50 by anareval         ###   ########.fr       */
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
	map->moves = 0;
	ft_save_map(map, argv[1]);
	ft_printf("Map Read.\n");
	ft_load_img(map);
}

static void	ft_map_checkers(t_map *map)
{
	ft_check_objcs(map);
	ft_check_map_limits(map);
	ft_check_game(map);
}

void	ft_exit(t_map *map)
{
	mlx_close_window(map->wind);
	ft_printf("Exiting...\n");
}

void	ft_win(t_map *map)
{
	mlx_close_window(map->wind);
	ft_printf("*************************************************\n");
	ft_printf("**  Y   Y  OOO  U   U     W     W  III  N   N  **\n");
	ft_printf("**   Y Y  O   O U   U     W  W  W   I   NN  N  **\n");
	ft_printf("**    Y   O   O U   U     W  W  W   I   N N N  **\n");
	ft_printf("**    Y   O   O U   U     W  W  W   I   N  NN  **\n");
	ft_printf("**    Y    OOO   UUU       WW WW   III  N   N  **\n");
	ft_printf("*************************************************\n");
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		ft_check_map_ext(argv[1]);
		ft_read_map(&map, argv[1]);
		map.wind = mlx_init(map.width * 50, map.height * 50, "so_long", false);
		ft_ini_dat(&map, argv);
		ft_printf("Starting map checking.\n");
		ft_map_checkers(&map);
		ft_printf("Game started...\n");
		ft_draw_map(&map);
		mlx_key_hook(map.wind, &ft_move_key, &map);
		mlx_loop(map.wind);
		mlx_terminate(map.wind);
		ft_printf("Game finished!\n");
		ft_free(&map);
		ft_printf("Free OK.\n");
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Error\nInvalid number of arguments.\n");
		return (EXIT_FAILURE);
	}
}
