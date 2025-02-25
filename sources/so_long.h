/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:31:21 by anareval          #+#    #+#             */
/*   Updated: 2025/02/25 19:29:46 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define WIDTH 2560
# define HEIGHT 1560

typedef struct s_dat_map
{
	int		height;
	int		width;
	char	**map;
}	t_dat_map;

typedef struct s_images
{
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
}	t_images;

void	ft_read_map(t_dat_map *map, char *file);

#endif
