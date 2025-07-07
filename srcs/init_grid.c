/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:51:11 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 10:36:16 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct_game(t_game *g)
{
	if (!g)
		return ;
	ft_bzero(g, sizeof(t_game));
	g->direction = NONE;
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
			free(line);
			line = get_next_line(fd);
		}
		if (line)
			free(line);
		close(fd);
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
		return (display_error_message("Failed to malloc grid"));
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

int	load_map(t_game *g, char *file)
{
	init_struct_game(g);
	init_height(file, g);
	if (!g->height)
	{
		display_error_message("Empty or invalid file");
		return (0);
	}
	init_grid(file, g);
	if (!g->grid)
		return (0);
	init_width_and_check_rectangularity(g);
	if (validate_map(g))
		return (1);
	return (0);
}
