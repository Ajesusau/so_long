/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:31:21 by anareval          #+#    #+#             */
/*   Updated: 2025/02/27 18:36:41 by anareval         ###   ########.fr       */
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

# define COLLECT	"img/collect.xmp42"
# define EMPTY		"img/empty.xmp42"
# define EXIT		"img/exit.xmp42"
# define PLAYER		"img/playes.xmp42"
# define WALL		"img/wall.xmp42"
# define WIN		"img/win.xmp42"

typedef struct s_img
{
	mlx_image_t	*collect;
	mlx_image_t	*empty;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*win;
}	t_img;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	void	*wind;
}	t_map;

void	ft_read_map(t_map *map, char *file);
void	ft_save_map(t_map *map, char *file);
void	ft_draw_map(t_map *map);
void	ft_load_img(t_map *map, t_img *img);
void	ft_fmalloc(void);
void	ft_free(t_map *map);

#endif
