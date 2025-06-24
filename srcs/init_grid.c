/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:51:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:56:28 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct_game(t_game *g)
{
	g->grid = NULL;
	g->width = 0;
	g->height = 0;
	g->collectibles = 0;
	g->player_count = 0;
	g->exit_count = 0;
	g->player_x = 0;
	g->player_y = 0;
}

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error: failed to open file\n"), -1);
	return (fd);
}

void	init_height(const char *file, t_game *g)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	fd = open_file(file);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			count++;
			line = get_next_line(fd);
		}
		close(fd);
		if (line)
			free(line);
		g->height = count;
	}
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

void	init_grid(const char *file, t_game *g)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	g->grid = malloc(sizeof(char *) * (g->height + 1));
	if (!g->grid)
		return (perror("Error: failed to malloc grid\n"));
	fd = open_file(file);
	if (fd >= 0)
	{
		i = 0;
		line = get_next_line(fd);
		while (line)
		{
			remove_newline(line);
			g->grid[i] = line;
			i++;
			line = get_next_line(fd);
		}
		g->grid[i] = NULL;
		if (line)
			free(line);
		close (fd);
	}
}
