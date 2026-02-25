/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:39:24 by addos-sa          #+#    #+#             */
/*   Updated: 2026/02/25 13:34:01 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ini_screen(t_screen *screen)
{
	screen = malloc(sizeof(t_screen));
}

int	ini_texture(t_textures *textures)
{
	textures = malloc(sizeof(t_textures));
}

int	ini_player(t_player *player)
{
	player = malloc(sizeof(t_player));
	player->position = malloc(sizeof(t_point));
	if (!player->position)
	{
		free(player);
		return (1);
	}
	player->position->x = 0;
	player->position->y = 0;
	player->angle = malloc(sizeof(t_point));
	if (!player->angle)
	{
		free(player);
		free(player->position);
		return (1);
	}
	player->angle->y = 0.66;
	player->angle->x = 0;
	return (0);
}

int	ini_game(t_cub3D *game)
{
	game->mlx = mlx_init(1280, 780, "Cub3d", 1);
	game->game_running = 0;
	game->image_c = 0;
	game->map_copy = NULL;
	if (ini_player(game->player) != 0)
		return (1);
	if (ini_textures(game->textures) != 0)
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
