/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:47:37 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/25 11:58:26 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void init_textures(t_cub3D *game)
{
	game->textures.north_t = game->textures.n_path;
	game->textures.east_t = game->textures.e_path;
	game->textures.south_t = game->textures.so_path;
	game->textures.west_t = game->textures.w_path;
}

t_cub3D init_screen(t_cub3D *game, char **map)
{
	parsing(game, map);
	init_textures(game);
	
}

t_cub3D	init_game(t_cub3D *game, char **map)
{
	//allocate memory to game struct
	init_screen(game, map);
	init_mlx(game);
	//iniciar pantalla
	game->game_running = true;
	//sacar juego por pantalla
	return (*game);
}
