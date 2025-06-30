/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:51:13 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 17:43:52 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		error_message("Wrong number of arguments");
		return (1);
	}
	if (!check_extension(av[1]))
		return (1);
	if (!load_map(&game, av[1]))
	{
		error_message("Could not load map");
		return (1);
	}
	show_game(&game);
	return (0);
}

// voir comment kill la fenetre car je crois que ca cause des leak