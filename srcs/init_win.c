/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:48:58 by cscache           #+#    #+#             */
/*   Updated: 2025/07/02 15:49:01 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *g)
{
	int	window_height;
	int	window_width;

	window_height = g->height * TILE_SIZE + MOVE_COUNT_ZONE;
	window_width = g->width * TILE_SIZE;
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		display_error_message("Failed to initialize MLX");
		clean_exit(g, EXIT_FAILURE);
	}
	g->mlx_win = mlx_new_window(g->mlx, window_width, window_height, "so long");
	if (!g->mlx_win)
	{
		display_error_message("Failed to open window");
		clean_exit(g, EXIT_FAILURE);
	}
}
