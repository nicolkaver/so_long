/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:59:36 by nboratko          #+#    #+#             */
/*   Updated: 2022/04/28 18:59:56 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	win_right_ok(t_game *game)
{
	if (game->map[game->chars->y][game->chars->x + 1] != 'E' ||
		(game->map[game->chars->y][game->chars->x + 1] == 'E' &&
		game->chars->collectible == 0))
		return (1);
	return (0);
}

int	win_up_ok(t_game *game)
{
	if (game->map[game->chars->y - 1][game->chars->x] != 'E' ||
		(game->map[game->chars->y - 1][game->chars->x] == 'E' &&
		game->chars->collectible == 0))
		return (1);
	return (0);
}

int	win_left_ok(t_game *game)
{
	if (game->map[game->chars->y][game->chars->x - 1] != 'E' ||
		(game->map[game->chars->y][game->chars->x - 1] == 'E' &&
		game->chars->collectible == 0))
		return (1);
	return (0);
}

int	win_down_ok(t_game *game)
{
	if (game->map[game->chars->y + 1][game->chars->x] != 'E' ||
		(game->map[game->chars->y + 1][game->chars->x] == 'E' &&
		game->chars->collectible == 0))
		return (1);
	return (0);
}
