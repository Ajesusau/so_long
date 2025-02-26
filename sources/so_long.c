/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:19 by anareval          #+#    #+#             */
/*   Updated: 2025/02/26 19:19:55 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		ft_read_map(&map, argv[1]);
		ft_save_map(&map, argv[1]);
		ft_draw_map(&map);
		map.wind = mlx_init(map.width * 40, map.height * 40, "42so_long", true);
		ft_printf("Game started...");
		mlx_loop(map.wind);
		mlx_terminate(map.wind);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Invalid number of arguments.");
		return (EXIT_FAILURE);
	}
}
