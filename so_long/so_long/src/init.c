/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:22:32 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:22:38 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (throw_error("MLX initialization failed"));
	parse_map(map_file, &game->map);
	game->win = mlx_new_window(game->mlx, 
		game->map.width * TILE_SIZE,
		game->map.height * TILE_SIZE, 
		"So Long - Stardew Escape");
	if (!game->win)
	{
		free(game->mlx);
		return (throw_error("Window creation failed"));
	}
	return (1);
}

void	load_textures(t_game *game)
{
	int		w;
	int		h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	game->map.wall_img = mlx_xpm_file_to_image(game->mlx, 
		"textures/wall.xpm", &w, &h);
	game->player.sprite = mlx_xpm_file_to_image(game->mlx, 
		"textures/player.xpm", &w, &h);
	game->map.collectible_img = mlx_xpm_file_to_image(game->mlx, 
		"textures/collectible.xpm", &w, &h);
	game->map.exit_img = mlx_xpm_file_to_image(game->mlx, 
		"textures/exit.xpm", &w, &h);
}
