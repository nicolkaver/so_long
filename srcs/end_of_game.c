/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:56:07 by nboratko          #+#    #+#             */
/*   Updated: 2022/04/29 14:15:05 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_mlx(t_data *mlx, char **map, int line_count)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->elem.floor.img);
		mlx_destroy_image(mlx->mlx, mlx->elem.wall.img);
		mlx_destroy_image(mlx->mlx, mlx->elem.player.img);
		mlx_destroy_image(mlx->mlx, mlx->elem.collect.img);
		mlx_destroy_image(mlx->mlx, mlx->elem.exit.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free_map(map, line_count);
	exit(0);
}

int	escape(t_game *game)
{
	ft_putendl_fd("You escaped before the game end. Try again !!!!", 1);
	free_mlx(game->mlx, game->map, game->chars->line_y);
	return (0);
}

void	end_msg(int count)
{
	ft_putstr_fd("Congratulations !! ", 1);
	ft_printf("You have finished the game in %d moves.\n", count);
}
