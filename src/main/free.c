/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:24:35 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/21 11:27:14 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void free_textures(t_cub3D *game)
{
	if (game->textures->north_t)
        mlx_delete_texture(game->textures->north_t);
    if (game->textures->south_t)
        mlx_delete_texture(game->textures->south_t);
    if (game->textures->east_t)
        mlx_delete_texture(game->textures->east_t);
    if (game->textures->west_t)
        mlx_delete_texture(game->textures->west_t);
	return ;
}

int free_game(t_cub3D *game, int mode)
{
	if (!game)
		return (mode);

	if (game->screen)
		free(game->screen);
	if (game->textures)
	{
		free_textures(game);
		free(game->textures);
	}
	if (game->player)
		free(game->player);
	free(game);
	return (mode);
}