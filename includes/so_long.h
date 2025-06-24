/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:49:15 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:58:13 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		player_count;
	int		exit_count;
	int		player_x;
	int		player_y;
}	t_game;

//init grid
void	init_struct_game(t_game *g);
int		open_file(const char *file);
void	init_height(const char *file, t_game *g);
void	remove_newline(char *line);
void	init_grid(const char *file, t_game *g);

//check grid
int		init_width_and_check_rectangularity(t_game *g);
int		check_walls(t_game *g);
int		count_elements(const char *s, char c);
int		is_in_dataset(char c);
int		check_rules_for_elements(t_game *g);
void	init_counters(t_game *g, char c, int x, int y);
int		check_elements(t_game *g);
void	validate_map(t_game *g);

//free
void	free_grid(t_game *g);

#endif