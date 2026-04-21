/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:47:37 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/20 18:03:49 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_image(t_cub3D *game)
{
	if (!game)
		return ;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img)
        return ((void)bad_init(game, 4));
    mlx_image_to_window(game->mlx, game->img, 0, 0);
	return ;
}

static void	init_player(t_cub3D *game)
{
	if (!game || !game->player)
		return ;
	game->player->position.x = 0;
	game->player->position.y = 0;
	game->player->angle = PI / 2;
	game->player->k_down = false;
	game->player->k_left = false;
	game->player->k_right = false;
	game->player->k_up = false;
	game->player->r_left = false;
	game->player->r_right = false;
}

static void init_textures(t_cub3D *game)
{
	if (!game || !game->textures)
		return ;
	game->textures->e_path = NULL;
	game->textures->n_path = NULL;
	game->textures->s_path = NULL;
	game->textures->w_path = NULL;
	game->textures->east_t = NULL;
	game->textures->north_t = NULL;
	game->textures->south_t = NULL;
	game->textures->west_t = NULL;
}

static void init_screen(t_cub3D *game)
{
	if (!game || !game->screen)
		return ;
	game->screen->grid = NULL;
	game->screen->floor_path = NULL;
	game->screen->ceiling_path = NULL;
	game->screen->rgb_floor = 0;
	game->screen->rgb_ceiling = 0;
	game->screen->n_player = 0;
	game->screen->height = 0;
	game->screen->width = 0;
}

t_cub3D	*init_game(t_cub3D *game)
{
	game->game_running = false;
	game->mlx = NULL;
	game->img = NULL;
	game->screen = (t_screen*)malloc(sizeof(t_screen));
	if (!game->screen)
		return (bad_init(game, 1));
	init_screen(game);
	game->textures = (t_textures*)malloc(sizeof(t_textures));
	if (!game->textures)
		return (bad_init(game, 2));
	init_textures(game);
	game->player = (t_player*)malloc(sizeof(t_player));
	if (!game->player)
		return (bad_init(game, 3));
	init_player(game);
	return (game);
}
