/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:32:56 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 11:33:17 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(const char *file)
{
	int	len;

	if (!file)
		return (display_error_message("Invalid file extension"), 0);
	len = ft_strlen(file);
	if (len < 5)
		return (display_error_message("Invalid file extension"), 0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		display_error_message("Invalid file extension");
		return (0);
	}
	return (1);
}

int	open_file(const char *file)
{
	int	fd;

	if (!file)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror(file);
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}
