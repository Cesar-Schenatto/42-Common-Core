/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:22:55 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:22:58 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_components(char **grid)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	y;
	int	x;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			p_count += (grid[y][x] == 'P');
			e_count += (grid[y][x] == 'E');
			c_count += (grid[y][x] == 'C');
		}
	}
	return (p_count == 1 && e_count == 1 && c_count >= 1);
}

int	validate_map(char *file)
{
	char	**grid;
	int		is_valid;

	grid = parse_map(file);
	if (!grid)
		return (0);
	is_valid = validate_components(grid)
		&& check_walls(grid)
		&& check_rectangular(grid)
		&& flood_fill_check(grid);
	free_grid(grid);
	return (is_valid);
}
