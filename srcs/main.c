/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:51:13 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 14:40:59 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_putendl_fd("Error : program need one file", 2);
		return (1);
	}
	show_game(&game, av[1]);
	return (0);
}
