/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:37:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 12:11:13 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *g)
{
	int	window_height;
	int	window_width;

	window_height = g->height * TILE_SIZE;
	window_width = g->width * TILE_SIZE;
	g->mlx = mlx_init;
	g->window = mlx_new_window(g->mlx, window_width, window_height, "so long");
}

void	init_images(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.player = mlx_xpm_file_to_image(g->mlx, "assets/player.xml", &img_width, &img_height);
}

void	render_map(t_game *g)
{
	
}

