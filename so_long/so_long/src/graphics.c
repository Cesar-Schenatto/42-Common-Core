/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:29:13 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:29:15 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	mlx_clear_window(game->mlx, game->win);
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, 
					game->map.wall_img, x*TILE_SIZE, y*TILE_SIZE);
			else if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, 
					game->map.collectible_img, x*TILE_SIZE, y*TILE_SIZE);
			else if (game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, 
					game->map.exit_img, x*TILE_SIZE, y*TILE_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, 
		game->player.sprite, 
		game->player.x*TILE_SIZE, 
		game->player.y*TILE_SIZE);
	return (0);
}
