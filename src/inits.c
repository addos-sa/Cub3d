/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:47:37 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/24 12:14:20 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_cub3D	init_game(t_cub3D *game, char **map)
{
	//allocate memory to game struct
	init_screen(game, map);
	//init_mlx()
	init_textures(game);
	game->game_running = true;
	//sacar juego por pantalla
	return (*game);
}
