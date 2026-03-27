/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:47:37 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/27 12:13:14 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void init_textures(t_cub3D *game)
{
	if (!game || !game->textures)
		return ;
	game->textures->e_path;
	game->textures->n_path;
	game->textures->s_path;
	game->textures->w_path;
	game->textures->east_t;
	game->textures->north_t;
	game->textures->south_t;
	game->textures->west_t;
}

static void init_screen(t_cub3D *game)
{
	if (!game || !game->screen)
		return ;
	game->screen->grid;
	game->screen->floor_path;
	game->screen->ceiling_path;
	game->screen->rgb_floor;
	game->screen->rgb_ceiling;
	game->screen->n_player;
	game->screen->height;
	game->screen->width;
}

static void init_gameinfo(t_cub3D *game)
{
	if (!game)
		return ;
	game->game_running = false;
	game->mlx = NULL;
}

t_cub3D	*init_game(char *map_path)
{
	t_cub3D *game;
	
	game = (t_cub3D*)malloc(sizeof(t_cub3D));
	if (!game)
		return (NULL);
	init_gameinfo(game);
	game->screen = (t_screen*)malloc(sizeof(t_screen));
	if (!game->screen)
		return (NULL);
	init_screen(game);
	game->textures = (t_textures*)malloc(sizeof(t_textures));
	if (!game->textures)
		return (NULL);
	init_textures(game);

	return (game);
}



// t_cub3D	init_game(t_cub3D *game, char *map_path)
// {
// 	game->mlx = mlx_init(1280, 780, "cub3D", 1);
// 	game->game_running = 0;
// 	game->image_c = 0;
// 	// game->map_copy = NULL;
// 	if (init_player(game->player) != 0)
// 		return (1);
// 	if (init_textures(game->textures) != 0)
// 	{
// 		free_player(game->player);
// 		free_game(game);
// 		return (1);
// 	}
// 	if (ini_screen(game->screen) != 0)
// 	{
// 		free_player(game->player);
// 		free_textures(game->textures);
// 		free_game(game);
// 		return (1);	
// 	}
// 	return (0);
// }
