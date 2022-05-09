/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:00:28 by nboratko          #+#    #+#             */
/*   Updated: 2022/04/28 19:13:46 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	direction(int keypress, t_game *game)
{
	if (keypress == 65307)
	{
		ft_putstr_fd("You escaped before the game end !!!", 1);
		free_mlx(game->mlx, game->map, game->chars->line_y);
	}
	else if (keypress == 100
		&& game->map[game->chars->y][game->chars->x + 1] != '1' &&
			win_right_ok(game))
		move_right(game);
	else if (keypress == 119
		&& game->map[game->chars->y - 1][game->chars->x] != '1' &&
		win_up_ok(game))
		move_up(game);
	else if (keypress == 97
		&& game->map[game->chars->y][game->chars->x - 1] != '1' &&
		win_left_ok(game))
		move_left(game);
	else if (keypress == 115
		&& game->map[game->chars->y + 1][game->chars->x] != '1' &&
		win_down_ok(game))
		move_down(game);
	return (0);
}

void	move_right(t_game *game)
{
	if (game->map[game->chars->y][game->chars->x + 1] == 'C')
		game->chars->collectible--;
	game->map[game->chars->y][game->chars->x] = '0';
	if (game->map[game->chars->y][game->chars->x + 1] == 'E' &&
		game->chars->collectible == 0)
	{
		end_msg(game->count);
		free_mlx(game->mlx, game->map, game->chars->line_y);
	}
	game->map[game->chars->y][game->chars->x + 1] = 'P';
	game->chars->x++;
	ft_putnbr_fd(++game->count, 1);
	write(1, "\n", 1);
	put_txt(game->map, *game->mlx, *game->chars);
}

void	move_up(t_game *game)
{
	if (game->map[game->chars->y - 1][game->chars->x] == 'C')
		game->chars->collectible--;
	game->map[game->chars->y][game->chars->x] = '0';
	if (game->map[game->chars->y - 1][game->chars->x] == 'E' &&
		game->chars->collectible == 0)
	{
		end_msg(game->count);
		free_mlx(game->mlx, game->map, game->chars->line_y);
	}
	game->map[game->chars->y - 1][game->chars->x] = 'P';
	game->chars->y--;
	ft_putnbr_fd(++game->count, 1);
	write(1, "\n", 1);
	put_txt(game->map, *game->mlx, *game->chars);
}

void	move_left(t_game *game)
{
	if (game->map[game->chars->y][game->chars->x - 1] == 'C')
		game->chars->collectible--;
	game->map[game->chars->y][game->chars->x] = '0';
	if (game->map[game->chars->y][game->chars->x - 1] == 'E'
		&& game->chars->collectible == 0)
	{
		end_msg(game->count);
		free_mlx(game->mlx, game->map, game->chars->line_y);
	}
	game->map[game->chars->y][game->chars->x - 1] = 'P';
	game->chars->x--;
	ft_putnbr_fd(++game->count, 1);
	write(1, "\n", 1);
	put_txt(game->map, *game->mlx, *game->chars);
}

void	move_down(t_game *game)
{
	if (game->map[game->chars->y + 1][game->chars->x] == 'C')
		game->chars->collectible--;
	game->map[game->chars->y][game->chars->x] = '0';
	if (game->map[game->chars->y + 1][game->chars->x] == 'E'
		&& game->chars->collectible == 0)
	{
		end_msg(game->count);
		free_mlx(game->mlx, game->map, game->chars->line_y);
	}
	game->map[game->chars->y + 1][game->chars->x] = 'P';
	game->chars->y++;
	ft_putnbr_fd(++game->count, 1);
	write(1, "\n", 1);
	put_txt(game->map, *game->mlx, *game->chars);
}
