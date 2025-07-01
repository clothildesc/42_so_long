/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:43 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 16:52:37 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_chicken_sprites(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.chicken[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-1.xpm", &img_width, &img_height);
	g->img.chicken[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-2.xpm", &img_width, &img_height);
	g->img.chicken[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-3.xpm", &img_width, &img_height);
	g->img.chicken[3] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-4.xpm", &img_width, &img_height);
	g->img.chicken[4] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-5.xpm", &img_width, &img_height);
	if (!g->img.chicken[0] || !g->img.chicken[1] \
		|| !g->img.chicken[2] || !g->img.chicken[3] \
		|| !g->img.chicken[4])
	{
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
	}
}

int	calculate_size_array_coordinates(t_game *g)
{
	int	x;
	int	y;
	int	size;

	size = 0;
	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[y][x] == '0')
				size++;
			x++;
		}
		y++;
	}
	return (size);
}

void	fill_array_positions(t_game *g, t_point *positions)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[y][x] == '0')
			{
				positions[i].x = x;
				positions[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

t_point	*create_array_positions(t_game *g, int size)
{
	t_point	*positions;

	if (size == 0)
		return (NULL);
	positions = malloc(sizeof(t_point) * size);
	if (!positions)
		return (NULL);
	fill_array_positions(g, positions);
	return (positions);
}

void	suffle(t_point *positions, int size)
{
	int		i;
	int		random_index;
	t_point	temp;

	i = size - 1;
	while (i >= 0)
	{
		random_index = rand () % (i + 1);
		temp = positions[i];
		positions[i] = positions[random_index];
		positions[random_index] = temp;
		i--;
	}
}

void	place_enemies(t_game *g, t_point *positions)
{
	int		i;

	i = 0;
	while (i < g->enemies_count)
	{
		g->grid[positions[i].y][positions[i].x] = 'M';
		i++;
	}
}

void	create_enemies(t_game *g)
{
	t_point	*positions;
	int		size;

	srand(time(NULL));
	g->enemies_count = (g->width * g->height) / 50;
	size = calculate_size_array_coordinates(g);
	if (size < g->enemies_count)
		g->enemies_count = size;
	positions = create_array_positions(g, size);
	if (positions && size > 0)
	{
		suffle(positions, size);
		place_enemies(g, positions);
		free(positions);
	}
}
