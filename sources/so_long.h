/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:31:21 by anareval          #+#    #+#             */
/*   Updated: 2025/02/26 21:03:41 by anareval         ###   ########.fr       */
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

# define COLLECT	"./img/collect.xpm42"
# define EMPTY		"./img/empty.xpm42"
# define EXIT		"./img/exit.xpm42"
# define PLAYER		"./img/playes.xpm42"
# define WALL		"./img/wall.xpm42"
# define WIN		"./img/win.xpm42"

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	void	*wind;
}	t_map;

typedef struct s_images
{
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*win;
}	t_images;

void	ft_read_map(t_map *map, char *file);
void	ft_save_map(t_map *map, char *file);
void	ft_draw_map(t_map *map);

#endif
