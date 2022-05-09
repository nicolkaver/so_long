/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:59:25 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/02 12:41:31 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	too_many_players(int index)
{
	if (index > 1)
		ft_putendl_fd("Attention, more than 1 player !", 2);
	return (1);
}

int	invalid_elem(char c, t_chars *chars, int i, int j)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'E')
	{
		chars->exit++;
		return (0);
	}
	else if (c == 'P')
	{
		chars->player++;
		if (chars->player > 1)
			return (too_many_players(chars->player));
		chars->x = j;
		chars->y = i;
		return (0);
	}
	else if (c == 'C')
	{
		chars->collectible++;
		return (0);
	}
	return (1);
}

void	check_elems(char **map, t_chars *chars)
{
	int	i;

	i = 0;
	if (chars->collectible < 1)
	{
		ft_putstr_fd("Error\nCollectible missing\n", 2);
		i++;
	}
	if (chars->exit < 1)
	{
		ft_putstr_fd("Error\nExit missing\n", 2);
		i++;
	}
	if (chars->player != 1)
	{
		ft_putstr_fd("Error\nPlayer missing\n", 2);
		i++;
	}
	if (i > 0)
		free_and_exit(map, chars->line_y, "Please correct your map");
}

void	parse_map(char **map, t_chars *chars)
{
	int		i;
	int		j;

	i = 0;
	while (map && chars && i < chars->line_y && map[i])
	{
		j = 0;
		while (i < chars->line_y && map[i][j])
		{
			if ((i == 0 || i == chars->line_y - 1) && map[i][j] != '1')
				free_and_exit(map, chars->line_y, "Error\nUnclosed map");
			else
				if ((j == 0 || j == chars->line_x - 1) && map[i][j] != '1')
					free_and_exit(map, chars->line_y, "Error\nUnclosed map");
			else if (invalid_elem(map[i][j], chars, i, j))
				free_and_exit(map, chars->line_y, "Error\nInvalid element");
			j++;
		}
		i++;
	}
	check_elems(map, chars);
	return ;
}
