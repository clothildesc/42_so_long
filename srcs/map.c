/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:07:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 12:29:14 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_map(t_map *m)
{
	m->grid = NULL;
	m->width = 0;
	m->height = 0;
	m->collectibles = 0;
	m->player_count = 0;
	m->exit_count = 0;
}

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("[so_long] open file"), -1);
	return (fd);
}

void	init_height(const char *file, t_map *m)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open_file(file);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			count++;
			line = get_next_line(fd);
		}
	}
	close(fd);
	m->height = count;
}

void	remove_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	init_grid(const char *file, t_map *m)
{
	int		fd;
	char	*line;
	int		i;

	m->grid = malloc(sizeof(char *) * (m->height + 1));
	if (!m->grid)
		return (perror("[so_long] malloc grid"));
	fd = open_file(file);
	if (fd >= 0)
	{
		i = 0;
		line = get_next_line(fd);
		while (line)
		{
			remove_newline(line);
			m->grid[i] = line;
			i++;
			line = get_next_line(fd);
		}
		m->grid[i] = NULL;
		close (fd);
	}
}

void	init_width(t_map *m)
{
	int	i;
	int	len;

	if (!m->grid)
		return ;
	len = ft_strlen(m->grid[0]);
	i = 1;
	while (m->grid[i])
	{
		if (len != ft_strlen(m->grid[i]))
			return (perror("[so_long] lines don't have same size"));
		len = ft_strlen(m->grid[i]);
		i++;
	}
	m->width = len;
}

int	main(void)
{
	t_map	map;
	int		i;

	i = 0;
	init_grid(&map);
	while (map.grid[i])
	{
		printf("%s", map.grid[i]);
		i++;
	}
	return (0);
}