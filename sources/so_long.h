/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:31:21 by anareval          #+#    #+#             */
/*   Updated: 2025/02/28 09:29:40 by anareval         ###   ########.fr       */
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

# define COLLECT	"./img/collect.png"
# define EMPTY		"./img/empty.png"
# define EXIT		"./img/exit.png"
# define PLAYER		"./img/player.png"
# define WALL		"./img/wall.png"
# define WIN		"./img/win.png"

typedef struct s_text
{
	mlx_texture_t	*collect;
	mlx_texture_t	*empty;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*win;
}	t_text;

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
	t_img	*img;
	t_text	*text;
	mlx_t	*wind;
}	t_map;

void	ft_read_map(t_map *map, char *file);
void	ft_save_map(t_map *map, char *file);
void	ft_draw_map(t_map *map);
void	ft_load_img(t_map *map);
void	ft_fmalloc(void);
void	ft_free(t_map *map);

#endif
