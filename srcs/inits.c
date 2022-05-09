/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:41:37 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/02 20:41:58 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_chars(t_chars *chars)
{
	chars->line_y = 0;
	chars->line_x = 0;
	chars->player = 0;
	chars->collectible = 0;
	chars->exit = 0;
}

void	init_txt(t_data *mlx, t_img *elem, char *path)
{
	elem->img = mlx_xpm_file_to_image(mlx->mlx, path, &elem->height,
			&elem->width);
}
