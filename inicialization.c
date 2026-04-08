/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:39:24 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/27 10:39:04 by addos-sa         ###   ########.fr       */
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
	player->pos = malloc(sizeof(t_point));
	if (!player->pos)
	{
		free(player);
		return (1);
	}
	player->pos->x = 0;
	player->pos->y = 0;
	player->angle = PI / 2;
	player->k_down = false;
	player->k_left = false;
	player->k_right = false;
	player->k_up = false;
	player->r_left = false;
	player->r_right = false;
	return (0);
}

int	ini_game(t_cub3D *game)
{
	game->mlx = mlx_init(1280, 780, "Cub3d", 1);
	if (!game->mlx)
		return (1);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (1);
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)//esto no estoy seguro si tiene que estar
		return (1);
	game->game_running = 0;
	game->image_c = 0;
	game->map_copy = NULL;
	if (ini_player(game->player) != 0)
		return (1);
	if (ini_texture(game->textures) != 0)
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
