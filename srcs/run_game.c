/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:39:46 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 10:33:50 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_error_message(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
}

void	initialize_and_start_game(t_game *g)
{
	init_window(g);
	init_images(g);
	create_enemies(g);
	render_map(g);
	mlx_hook(g->mlx_win, 17, 0, close_window, g);
	mlx_key_hook(g->mlx_win, handle_key_input, g);
	mlx_loop_hook(g->mlx, handle_tick, g);
	mlx_loop(g->mlx);
}
