/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:07:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 18:50:59 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;
	char	**grid_cpy;
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
	grid_cpy = create_grid_cpy(game.grid, game.height);
	validate_map(&game);
	i = 0;
	while (grid_cpy && grid_cpy[i])
	{
		printf("%s\n", grid_cpy[i]);
		i++;
	}
	free_grid(&game);
	return (0);
}
