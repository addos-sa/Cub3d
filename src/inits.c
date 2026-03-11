/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:47:37 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/25 17:58:26 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int init_textures(t_textures *textures)
{

}

int init_screen(t_cub3D *game, char **map)
{
	parsing(game, map);
	init_textures(game);
	
}

int	init_game(t_cub3D *game, char **map)
{
	game->mlx = mlx_init(1280, 780, "Cub3d", 1);
	game->game_running = 0;
	game->image_c = 0;
	game->map_copy = NULL;
	if (init_player(game->player) != 0)
		return (1);
	if (init_textures(game->textures) != 0)
	{
		free_player(game->player);
		free_game(game);
		return (1);
	}
	if (ini_screen(game->screen) != 0)
	{
		free_player(game->player);
		free_textures(game->textures);
		free_game(game);
		return (1);	
	}
	return (0);
}
