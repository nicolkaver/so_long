/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:58:42 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/05 16:06:51 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define FLOOR	"textures/floor.xpm"
# define WALL	"textures/wall.xpm"
# define PLAYER	"textures/player.xpm"
# define COLLECT	"textures/collect.xpm"
# define EXIT	"textures/exit.xpm"

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_img {
	void	*img;
	int		height;
	int		width;
}				t_img;

typedef struct s_elem {
	t_img	floor;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
}				t_elem;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_elem	elem;
	int		x;
	int		y;
}				t_data;

typedef struct s_chars
{
	int	line_y;
	int	line_x;
	int	player;
	int	collectible;
	int	exit;
	int	x;
	int	y;
}				t_chars;

typedef struct s_game {
	t_data	*mlx;
	t_chars	*chars;
	char	**map;
	int		count;
}				t_game;

int		is_wrong_elem(char c, t_chars *chars, int i, int j);
void	check_elems(char **map, t_chars *chars);
void	parse_map(char **map, t_chars *chars);
void	ft_perror(void);
void	free_map(char **map, int index);
void	free_and_exit(char **map, int index, char *msg);
void	free_unrect(char **map, int index, char *msg);
void	error_msg(char *msg);
void	free_mlx(t_data *mlx, char **map, int line_count);
int		escape(t_game *game);
void	init_txt(t_data *mlx, t_img *txt, char *path);
void	get_elem_txt(t_data *mlx);
void	open_map(char **map, t_chars chars);
void	put_txt(char **map, t_data mlx, t_chars chars);
void	get_txt(t_data *mlx);
void	draw_txt(char c, t_data mlx, int i, int j);
int		direction(int keycode, t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
int		win_right_ok(t_game *game);
int		win_up_ok(t_game *game);
int		win_left_ok(t_game *game);
int		win_down_ok(t_game *game);
void	end_msg(int count);
int		too_many_players(int index);
void	init_chars(t_chars *chars);
int		check_path(char *path);

#endif
