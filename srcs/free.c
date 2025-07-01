/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:42:56 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 16:55:36 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_player_sprites(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (g->img.player.walk_up[i])
			mlx_destroy_image(g->mlx, g->img.player.walk_up[i]);
		if (g->img.player.walk_down[i])
			mlx_destroy_image(g->mlx, g->img.player.walk_down[i]);
		if (g->img.player.walk_left[i])
			mlx_destroy_image(g->mlx, g->img.player.walk_left[i]);
		if (g->img.player.walk_right[i])
			mlx_destroy_image(g->mlx, g->img.player.walk_right[i]);
		i++;
	}
}

void	destroy_other_images(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g->img.chicken[i])
			mlx_destroy_image(g->mlx, g->img.chicken[i]);
		i++;
	}
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->img.floor);
	if (g->img.wall)
		mlx_destroy_image(g->mlx, g->img.wall);
	if (g->img.collectible)
		mlx_destroy_image(g->mlx, g->img.collectible);
	if (g->img.exit)
		mlx_destroy_image(g->mlx, g->img.exit);
	if (g->img.player_win)
		mlx_destroy_image(g->mlx, g->img.player_win);
	if (g->img.black)
		mlx_destroy_image(g->mlx, g->img.black);
}

void	free_grid(t_game *g)
{
	int	i;

	i = 0;
	if (g->grid)
	{
		while (g->grid[i])
			free(g->grid[i++]);
		free(g->grid);
	}
}

void	clean_exit(t_game *g, int exit_code)
{
	if (g->mlx)
	{
		destroy_player_sprites(g);
		destroy_other_images(g);
		if (g->mlx_win)
			mlx_destroy_window(g->mlx, g->mlx_win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free_grid(g);
	exit(exit_code);
}

void	free_grid_cpy(char **grid_cpy)
{
	int	i;

	i = 0;
	if (grid_cpy)
	{
		while (grid_cpy[i])
		{
			free(grid_cpy[i]);
			i++;
		}
		free(grid_cpy);
	}
}
