/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:31:21 by anareval          #+#    #+#             */
/*   Updated: 2025/03/07 14:40:11 by anareval         ###   ########.fr       */
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
	int		x;
	int		y;
	int		player;
	int		collect;
	int		finish;
	int		moves;
	t_img	*img;
	t_text	*text;
	mlx_t	*wind;
}	t_map;

typedef struct s_mcheck
{
	char	**map;
	int		collect;
	int		finish;
}	t_mcheck;

//ft_check_game.c------------------------------------------
//static void	ft_charger_checker(t_mcheck *mcheck, t_map *map);
//static void	ft_flood_fill(t_mcheck *mcheck, int y, int x);
void	ft_check_map_limits(t_map *map);
void	ft_check_game(t_map *map);

//ft_check_map.c-------------------------------------------
//static void	ft_fail_map(void);
//static void	ft_set_player_xy(t_map *map, int i, int j);
//static void	ft_check_extra_objcs(char c);
void	ft_check_objcs(t_map *map);
void	ft_check_map_ext(char *file);

//ft_draw_map.c--------------------------------------------
//static void	ft_put_player(t_map *map, int i, int j);
//static void	ft_put_collect(t_map *map, int i, int j);
//static void	ft_put_exit(t_map *map, int i, int j);
void	ft_draw_map(t_map *map);
void	ft_rdraw_map(t_map *map);

//ft_free.c------------------------------------------------
//static void	ft_delete_text(t_map *map);
//static void	ft_free_map(t_map *map);
void	ft_free_checker(t_mcheck *mcheck, t_map *map);
void	ft_free(t_map *map);

//ft_load_img.c--------------------------------------------
//static void	ft_load_png(t_text *text);
void	ft_load_img(t_map *map);
void	ft_reload_img(t_map *map);

//ft_move_key.c--------------------------------------------
//static void	ft_key_w(t_map *map);
//static void	ft_key_a(t_map *map);
//static void	ft_key_s(t_map *map);
//static void	ft_key_d(t_map *map);
void	ft_move_key(mlx_key_data_t keydata, void *param);

//ft_read_map.c--------------------------------------------
//static void	ft_fmalloc(void);
void	ft_read_map(t_map *map, char *file);
void	ft_save_map(t_map *map, char *file);

//so_long.c--------------------------------------------
//static void	ft_ini_dat(t_map *map, char *argv[]);
//static void	ft_map_checkers(t_map *map);
void	ft_exit(t_map *map);
void	ft_win(t_map *map);
//int	main(int argc, char *argv[]);

#endif
