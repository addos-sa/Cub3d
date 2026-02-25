/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:39:24 by addos-sa          #+#    #+#             */
/*   Updated: 2026/02/25 08:52:38 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ini_game(t_game *game)
{
	game->mlx = mlx_init(1280, 780, "Cub3d");
	game->img = mlx_new_window(game->mlx, );
	game->window = mlx_new_image(game->mlx, 1280, 780);
}
