/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:07:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:38:32 by cscache          ###   ########.fr       */
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

int	init_width_and_check_rectangularity(t_game *g)
{
	int		i;
	size_t	len;

	if (!g->grid)
		return (0);
	len = ft_strlen(g->grid[0]);
	i = 1;
	while (g->grid[i])
	{
		if (len != ft_strlen(g->grid[i]))
			return (0);
		len = ft_strlen(g->grid[i]);
		i++;
	}
	g->width = (int)len;
	return (1);
}

int	check_walls(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[0][x] != '1' || g->grid[g->height - 1][x] != '1' \
				|| g->grid[y][0] != '1' || g->grid[y][g->width - 1] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
int	 count_elements(const char *s, char c)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			count++;
		else
			i++;
	}
	if (str[i] == (unsigned char)c)
		count++;
	return (count);
}

int	is_in_dataset(char c)
{
	char	*dataset;
	int		i;

	dataset = "PEC01";
	i = 0;
	while (dataset[i])
	{
		if (c == dataset[i])
			return (1);
		i++;
	}
	return (0);
}

int check_rules_for_elements(t_game *g)
{
	if (g->player_count != 1)
		return (ft_printf("Error: map must contain exactly one player\n"), 0);
	else if (g->exit_count != 1)
		return (ft_printf("Error: map must contain exactly one exit\n"), 0);
	else if (g->collectibles < 1)
		return (ft_printf("Error: map must contain at least 1 collectible\n"), 0);
	return (1);
}

void	init_counters(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		(g->player_count)++;
		g->player_x = x;
		g->player_y = y;
	}
	else if (c == 'C')
		(g->collectibles)++;
	else if (c == 'E')
		(g->exit_count)++;
}

int	check_elements(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (!is_in_dataset(g->grid[y][x]))
				return (ft_printf("Error: element is not allowed\n"), 0);
			init_counters(g, g->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	return (check_rules_for_elements(g));
}

void	validate_map(t_game *g)
{
	if (!g->grid)
		ft_printf("Error: map does not exist\n");
	if (!init_width_and_check_rectangularity(g))
		ft_printf("Error: map is not rectangular\n");
	if (!check_walls(g))
		ft_printf("Error: map is not surronded by walls\n");
	if (!check_elements(g))
		ft_printf("Error: map must contain valid elements\n");
	else
	{
		ft_printf("MAP IS VALID\n");
		return ;
	}
	free_grid(g);
	exit(EXIT_FAILURE);
}
int	main(void)
{
	t_game	game;
	int		i;

	i = 0;
	init_struct_game(&game);
	init_height("maps/basic.ber", &game);
	init_grid("maps/basic.ber", &game);
	init_width_and_check_rectangularity(&game);
	while (game.grid && game.grid[i])
	{
		printf("%s\n", game.grid[i]);
		i++;
	}
	printf("height: %d\n", game.height);
	printf("width: %d\n", game.width);
	check_walls(&game);
	validate_map(&game);
	free_grid(&game);
	return (0);
}
