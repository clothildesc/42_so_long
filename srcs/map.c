/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:07:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:54:03 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;
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
	validate_map(&game);
	free_grid(&game);
	return (0);
}
