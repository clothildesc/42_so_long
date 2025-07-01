/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:53:34 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 11:53:36 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
