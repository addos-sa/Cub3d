/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:39:24 by addos-sa          #+#    #+#             */
/*   Updated: 2026/02/25 11:59:15 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ini_game(t_cub3D *game)
{
	game->mlx = mlx_init(1280, 780, "Cub3d", 1);
	game->game_running = 0;
	game->image_c = 0;
	game->map_copy = NULL;
	game->player = malloc(sizeof(t_player));
	game->screen = malloc(sizeof(t_screen));
	game->textures = malloc(sizeof(t_textures));
}
