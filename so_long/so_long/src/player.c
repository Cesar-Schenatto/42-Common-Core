/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:31:23 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:31:27 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (0);
	return (game->map.grid[new_y][new_x] != '1');
}

static void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.collectibles--;
		game->map.grid[y][x] = '0';
	}
}

static void	handle_exit(t_game *game)
{
	if (game->map.collectibles == 0)
	{
		ft_printf("Congratulations! You escaped in %d moves!\n",
			game->player.moves);
		clean_exit(game);
	}
	else
		ft_printf("Collect all fish before escaping!\n");
}

void	move_player(t_game *game, int dx, int dy)
{
	const int	new_x = game->player.x + dx;
	const int	new_y = game->player.y + dy;

	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'E')
		return (handle_exit(game));
	handle_collectible(game, new_x, new_y);
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	render_frame(game);
}
