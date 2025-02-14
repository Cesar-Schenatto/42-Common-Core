/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:40:56 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/14 19:42:27 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"       // MiniLibX
# include "libft.h"     // Your libft

# define TILE_SIZE 64   // Stardew-like tile size
# define KEY_ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_player {
    int     x;
    int     y;
    int     moves;
    void    *sprite;
} t_player;

typedef struct s_map {
    char    **grid;
    int     width;
    int     height;
    int     collectibles;
    void    *wall_img;
    void    *exit_img;
    void    *collectible_img;
} t_map;

typedef struct s_game {
    void        *mlx;
    void        *win;
    t_map       map;
    t_player    player;
} t_game;

// Function declarations
int     validate_map(char *file);
void    load_textures(t_game *game);
void    render_frame(t_game *game);
int     handle_keypress(int keycode, t_game *game);

# endif
