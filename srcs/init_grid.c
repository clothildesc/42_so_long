/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothildescache <clothildescache@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:51:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 23:28:08 by clothildesc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct_game(t_game *g)
{
	if (!g)
		return ;
	ft_bzero(g, sizeof(t_game));
}

int	check_extension(const char *file)
{
	int	len;

	if (!file)
		return (error_message("Invalid file extension"), 0);
	len = ft_strlen(file);
	if (len < 5)
		return (error_message("Invalid file extension"), 0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		error_message("Invalid file extension");
		return (0);
	}
	return (1);
}

int	open_file(const char *file)
{
	int	fd;

	if (!file)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror(file);
		return (-1);
	}
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
			free(line);
			line = get_next_line(fd);
		}
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
		return (error_message("Failed to malloc grid"));
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
			free(line);
			line = get_next_line(fd);
		}
		g->grid[i] = NULL;
		close (fd);
	}
}

int	load_map(t_game *g, char *file)
{
	init_struct_game(g);
	init_height(file, g);
	if (!g->height)
	{
		error_message("Empty or invalid file");
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
