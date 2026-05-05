/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:04:24 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:32 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

void	mouse_movement(t_cub3D *game)
{
	int32_t	x;
	int32_t	y;
	int32_t	center;
	double	angle_speed;

	center = WIDTH / 2;
	angle_speed = 0.0015;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (x != center)
	{
		game->player->angle += (x - center) * angle_speed;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		mlx_set_mouse_pos(game->mlx, center, HEIGHT / 2);
	}
}
