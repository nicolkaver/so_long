/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:06:15 by nboratko          #+#    #+#             */
/*   Updated: 2022/05/09 16:01:30 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_filename(char *filename)
{
	int		len;
	char	*ext;

	len = ft_strlen(filename);
	if (len < 9)
		error_msg("Error\nInvalid filename");
	ext = ft_strnstr(filename, ".ber", len);
	if (!ext)
		error_msg("Error\nInvalid extension");
}

void	get_map(int fd, char **map, t_chars *chars)
{
	int	i;

	i = 0;
	map[i] = get_next_line(fd);
	if (!map[i])
		free_and_exit(map, i, "Error\nGnl failed");
	i++;
	while (i < chars->line_y)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_and_exit(map, i, "Error\nGnl failed");
		if (ft_strlen(map[i]) != chars->line_x)
			free_unrect(map, i, "Error\nMap is not rectangular");
		i++;
	}
	parse_map(map, chars);
	get_next_line(1025);
}

char	**malloc_map(int fd, t_chars *chars)
{
	char	**map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		get_next_line(1025);
		error_msg("Error\nIncorrect file");
	}
	chars->line_x = ft_strlen(line);
	while (line)
	{
		free(line);
		(chars->line_y)++;
		line = get_next_line(fd);
	}
	map = malloc(sizeof(char *) *(chars->line_y));
	if (!map)
		ft_perror();
	return (map);
}

int	check_path(char *path)
{
	int		fd;
	char	*buf;
	ssize_t	nbyte;
	int		buf_size;

	nbyte = 1;
	buf_size = 1;
	buf = malloc(sizeof(char) * buf_size + 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMissing texture, upload all .xpm files");
		return (1);
	}
	nbyte = read(fd, buf, buf_size);
	if (nbyte == -1)
	{
		ft_printf("Error\nEntered texture is a directory");
		free(buf);
		return (1);
	}
	free(buf);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_chars	chars;
	char	**map;

	if (ac != 2)
		error_msg("Error\nInvalid number of arguments");
	if (check_path(FLOOR) || check_path(WALL) || check_path(EXIT)
		|| check_path(PLAYER) || check_path(COLLECT))
		return (1);
	init_chars(&chars);
	check_filename(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_perror();
	map = malloc_map(fd, &chars);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_perror();
	get_map(fd, map, &chars);
	open_map(map, chars);
	get_next_line(1025);
	free_map(map, chars.line_y);
	return (1);
}
