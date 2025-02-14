/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:21:47 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:42:51 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "so_long.h"

static int	clean_exit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_grid(game->map.grid);
	exit(0);
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 0, clean_exit, game);
	mlx_loop_hook(game->mlx, render_frame, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (throw_error("Usage: ./so_long maps/map.ber"));
	ft_memset(&game, 0, sizeof(t_game));
	if (!validate_map(argv[1]))
		return (EXIT_FAILURE);
	if (!init_game(&game, argv[1]))
	{
		free_grid(game.map.grid);
		return (EXIT_FAILURE);
	}
	load_textures(&game);
	init_hooks(&game);
	mlx_loop(game.mlx);
	clean_exit(&game);
	return (EXIT_SUCCESS);
}

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 0, on_window_close, game);
	mlx_loop_hook(game->mlx, render_frame, game);
}
