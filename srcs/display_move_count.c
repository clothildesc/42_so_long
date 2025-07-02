/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:54:29 by cscache           #+#    #+#             */
/*   Updated: 2025/07/02 16:04:01 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_black_move_zone(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->width * TILE_SIZE)
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.black, \
								i, g->height * TILE_SIZE);
		i += TILE_SIZE;
	}
}

void	display_move_count(t_game *g)
{
	char	*str;

	str = ft_itoa(g->move_count);
	if (g->game_lose)
	{
		mlx_string_put(g->mlx, g->mlx_win, 15, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, "OH NO! GAME OVER... Total move : ");
		mlx_string_put(g->mlx, g->mlx_win, 100, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, str);
		ft_printf("OH NO! GAME OVER... Total move : %d\n", g->move_count);
	}
	else if (!g->game_won)
	{
		mlx_string_put(g->mlx, g->mlx_win, 15, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, "Total moves: ");
		mlx_string_put(g->mlx, g->mlx_win, 100, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, str);
		ft_printf("Total moves: %d\n", g->move_count);
	}
	else
	{
		mlx_string_put(g->mlx, g->mlx_win, 15, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, "CONGRATS! Total move : ");
		mlx_string_put(g->mlx, g->mlx_win, 160, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, str);
		ft_printf("CONGRATS! You won with: %d\n", g->move_count);
	}
	free(str);
}
