/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:24:06 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/11 13:30:14 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int validate_texture_files(t_textures *textures)
{

}

static int validate_colors(t_screen *screen)
{

}

static int validate_map(t_cub3D *game)
{

}

int	validate_parsed_data(t_cub3D *game)
{
	if (!game->textures->n_path || !game->textures->so_path
		|| !game->textures->w_path || !game->textures->e_path)
		return (printf("Error\n Missing texture path\n"), 1);
	if (!game->screen->floor_path || !game->screen->ceiling_path)
		return (printf("Error\n Missing color definition\n"), 1);
	if (validate_texture_files(game->textures))
		return (1);
	if (validate_colors(game->screen))
		return (1);
	if (!game->screen->grid)
		return (printf("Error\n No map found\n"), 1);
	if (validate_map(game) != 0)
		return (1);
	return (0);
}
