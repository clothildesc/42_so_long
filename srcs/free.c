/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:42:56 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 17:19:52 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_grid_and_exit(t_game *g)
{
	int	i;

	i = 0;
	if (g->grid)
	{
		while (g->grid[i])
		{
			free(g->grid[i]);
			i++;
		}
		free(g->grid);
	}
	exit(EXIT_FAILURE);
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

void	error_message(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
}
