/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:52:49 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:52:50 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_width_and_check_rectangularity(t_game *g)
{
	int		i;
	size_t	len;

	if (!g->grid)
		return (0);
	len = ft_strlen(g->grid[0]);
	i = 1;
	while (g->grid[i])
	{
		if (len != ft_strlen(g->grid[i]))
			return (0);
		len = ft_strlen(g->grid[i]);
		i++;
	}
	g->width = (int)len;
	return (1);
}

int	check_walls(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[0][x] != '1' || g->grid[g->height - 1][x] != '1' \
				|| g->grid[y][0] != '1' || g->grid[y][g->width - 1] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_elements(const char *s, char c)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			count++;
		else
			i++;
	}
	if (str[i] == (unsigned char)c)
		count++;
	return (count);
}

int	is_in_dataset(char c)
{
	char	*dataset;
	int		i;

	dataset = "PEC01";
	i = 0;
	while (dataset[i])
	{
		if (c == dataset[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_rules_for_elements(t_game *g)
{
	if (g->player_count != 1)
		return (ft_putendl_fd("Error: map must contain exactly \
								one player\n", 2), 0);
	else if (g->exit_count != 1)
		return (ft_putendl_fd("Error: map must contain exactly \
								one exit\n", 2), 0);
	else if (g->collectibles < 1)
		return (ft_putendl_fd("Error: map must contain at least one \
								collectible\n", 2), 0);
	return (1);
}