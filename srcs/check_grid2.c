/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:57:37 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 11:12:48 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_counters(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		(g->player_count)++;
		g->player_x = x;
		g->player_y = y;
		g->grid[y][x] = '0';
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
				return (display_error_message("Element is not allowed"), 0);
			init_counters(g, g->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	return (check_rules_for_elements(g));
}

void	flood_fill(char **grid_cpy, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (grid_cpy[row][col] == '1' || grid_cpy[row][col] == 'X')
		return ;
	grid_cpy[row][col] = 'X';
	flood_fill(grid_cpy, size, row - 1, col);
	flood_fill(grid_cpy, size, row + 1, col);
	flood_fill(grid_cpy, size, row, col - 1);
	flood_fill(grid_cpy, size, row, col + 1);
}

char	**create_grid_cpy(char **grid, int size)
{
	char	**grid_cpy;
	int		i;

	i = 0;
	if (!grid)
		return (NULL);
	grid_cpy = malloc(sizeof(char *) * (size + 1));
	if (!grid_cpy)
		return (NULL);
	while (grid[i] && i < size)
	{
		grid_cpy[i] = ft_strdup(grid[i]);
		if (!grid_cpy[i])
		{
			while (--i >= 0)
				free(grid_cpy[i]);
			free(grid_cpy);
			return (NULL);
		}
		i++;
	}
	grid_cpy[i] = NULL;
	return (grid_cpy);
}

int	check_accessility(t_game *g)
{
	char	**grid_cpy;
	t_point	size;
	int		x;
	int		y;

	grid_cpy = create_grid_cpy(g->grid, g->height);
	if (!grid_cpy)
		return (0);
	size.x = g->width;
	size.y = g->height;
	flood_fill(grid_cpy, size, g->player_y, g->player_x);
	y = 0;
	while (grid_cpy[y])
	{
		x = 0;
		while (grid_cpy[y][x])
		{
			if (grid_cpy[y][x] == 'C' || grid_cpy[y][x] == 'E')
				return (free_grid_cpy(grid_cpy), 0);
			x++;
		}
		y++;
	}
	free_grid_cpy(grid_cpy);
	return (1);
}

int	grid_size(t_game *g)
{
	if ((g->height * TILE_SIZE + MOVE_COUNT_ZONE) > 1080 \
	|| (g->width * TILE_SIZE) > 1920)
		return (0);
	return (1);
}

int	validate_map(t_game *g)
{
	if (!g->grid)
		display_error_message("Map does not exist");
	else if (!init_width_and_check_rectangularity(g))
		display_error_message("Map is not rectangular");
	else if (!check_walls(g))
		display_error_message("Map is not surronded by walls");
	else if (!check_elements(g))
		display_error_message("Map must contain valid elements");
	else if (!check_accessility(g))
		display_error_message("Not all collectibles & exit are accessible");
	else if (!grid_size(g))
		display_error_message("Map is to big for standard screen");
	else
		return (1);
	clean_exit(g, EXIT_FAILURE);
	return (0);
}
