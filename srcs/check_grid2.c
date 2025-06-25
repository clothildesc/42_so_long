/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:57:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 12:17:29 by cscache          ###   ########.fr       */
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
				return (ft_putendl_fd("Error: element is not allowed\n", 2), 0);
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

int	validate_map(t_game *g)
{
	if (!g->grid)
		ft_putendl_fd("Error: map does not exist\n", 2);
	else if (!init_width_and_check_rectangularity(g))
		ft_putendl_fd("Error: map is not rectangular\n", 2);
	else if (!check_walls(g))
		ft_putendl_fd("Error: map is not surronded by walls\n", 2);
	else if (!check_elements(g))
		ft_putendl_fd("Error: map must contain valid elements\n", 2);
	else if (!check_accessility(g))
		ft_putendl_fd("Error: not all collectibles & exit are accessible\n", 2);
	else
	{
		ft_printf("MAP IS VALID\n");
		return (1);
	}
	free_grid(g);
	exit(EXIT_FAILURE);
	return (0);
}

