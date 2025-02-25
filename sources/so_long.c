/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:19 by anareval          #+#    #+#             */
/*   Updated: 2025/02/25 12:43:32 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char *argv[])
{

	if (argc == 2)
	{
		char	*map;
		map = argv[2];
		mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
		if (!mlx)
			ft_error();

		mlx_image_t* img = mlx_new_image(mlx, 256, 256);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error();

		mlx_put_pixel(img, 0, 0, 0xFF0000FF);

		mlx_loop_hook(mlx, ft_hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Numero de argumantos no valido.");
		return (0);
	}
}
