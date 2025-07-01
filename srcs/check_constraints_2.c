/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:53:24 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 11:53:27 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	else if (!grid_size(g))
		display_error_message("Map is to big for standard screen");
	else if (!init_width_and_check_rectangularity(g))
		display_error_message("Map is not rectangular");
	else if (!check_walls(g))
		display_error_message("Map is not surronded by walls");
	else if (!check_elements(g))
		display_error_message("Map must contain valid elements");
	else if (!check_accessility(g))
		display_error_message("Not all collectibles & exit are accessible");
	else
		return (1);
	clean_exit(g, EXIT_FAILURE);
	return (0);
}
