/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:36:17 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/21 11:39:06 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_image(t_cub3D *game)
{
	if (!game)
		return ;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img)
        return ((void)bad_init(game, 5));
    mlx_image_to_window(game->mlx, game->img, 0, 0);
	return ;
}