/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:00:04 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/05 22:01:50 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_perror(void)
{
	perror("Error\n");
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_and_exit(char **map, int index, char *msg)
{
	int	i;

	i = 0;
	get_next_line(1025);
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_unrect(char **map, int index, char *msg)
{
	int	i;

	i = 0;
	get_next_line(1025);
	while (i <= index)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
