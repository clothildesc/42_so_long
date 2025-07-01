/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:43 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 12:42:32 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_chicken_sprites(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "assets/wall-2.xpm", \
										&img_width, &img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", \
										&img_width, &img_height);
	g->img.collectible = mlx_xpm_file_to_image(g->mlx, "assets/collectible.xpm"\
										, &img_width, &img_height);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "assets/exit-1.xpm", \
										&img_width, &img_height);
	g->img.player_win = mlx_xpm_file_to_image(g->mlx, "assets/exit-2.xpm", \
										&img_width, &img_height);
	g->img.black = mlx_xpm_file_to_image(g->mlx, "assets/black.xpm", \
										&img_width, &img_height);
	if (!g->img.wall || !g->img.floor || !g->img.collectible \
		|| !g->img.exit || !g->img.player_win || !g->img.black)
	{
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
	}
}