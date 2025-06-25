/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:51:13 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 12:20:29 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		perror("Error : program need one file");
		return (1);
	}
	load_map(&game, av[1]);
	return (0);
}
