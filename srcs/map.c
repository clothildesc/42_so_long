/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:07:11 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 12:21:11 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid && grid[i])
	{
		printf("%s\n", grid[i]);
		i++;
	}
}

int	load_map(t_game *g, char *file)
{
	init_struct_game(g);
	init_height(file, g);
	init_grid(file, g);
	init_width_and_check_rectangularity(g);
	if (validate_map(g))
		return (1);
	return (0);
}
