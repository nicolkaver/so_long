/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:54:52 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/02 20:43:58 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_elem_txt(t_data *mlx)
{
	init_txt(mlx, &mlx->elem.floor, FLOOR);
	init_txt(mlx, &mlx->elem.wall, WALL);
	init_txt(mlx, &mlx->elem.player, PLAYER);
	init_txt(mlx, &mlx->elem.collect, COLLECT);
	init_txt(mlx, &mlx->elem.exit, EXIT);
}

void	draw_txt(char c, t_data mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.elem.wall.img,
			(mlx.elem.wall.width * j), (mlx.elem.wall.height * i));
	else if (c == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.elem.floor.img,
			(mlx.elem.floor.width * j), (mlx.elem.floor.height * i));
	else if (c == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.elem.player.img,
			(mlx.elem.player.width * j), (mlx.elem.player.height * i));
	else if (c == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.elem.exit.img,
			(mlx.elem.exit.width * j), (mlx.elem.exit.height * i));
	else if (c == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.elem.collect.img,
			(mlx.elem.collect.width * j), (mlx.elem.collect.height * i));
}

void	put_txt(char **map, t_data mlx, t_chars chars)
{
	int	i;
	int	j;

	i = 0;
	while (i < chars.line_y)
	{
		j = 0;
		while (j < chars.line_x)
		{
			draw_txt(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}

void	open_map(char **map, t_chars chars)
{
	t_data	mlx;
	t_game	game;

	game.map = map;
	game.chars = &chars;
	game.count = 0;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		free_map(map, chars.line_y);
		exit(1);
	}
	get_elem_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.elem.floor.width * chars.line_x),
			(mlx.elem.floor.height * chars.line_y), "So Long !");
	put_txt(map, mlx, chars);
	game.mlx = &mlx;
	mlx_hook(mlx.win, 17, 0L, escape, &game);
	mlx_hook(mlx.win, 2, 1L << 0, direction, &game);
	mlx_loop(mlx.mlx);
}
