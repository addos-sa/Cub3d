/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:37:06 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:21 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

void	close_all_doors(t_cub3D *game)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (game->screen->grid[y])
	{
		while (game->screen->grid[y][x] != '\0')
		{
			if (game->screen->grid[y][x] == 'd')
			{
				game->screen->grid[y][x] = 'D';
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	is_there_a_door(t_cub3D *game)
{
	int	y;
	int	x;

	y = game->player->position.y - 1;
	x = game->player->position.x - 1;
	close_all_doors(game);
	while (y <= game->player->position.y + 1)
	{
		while (x <= game->player->position.x + 1)
		{
			if (game->screen->grid[y][x] == 'D')
			{
				game->screen->grid[y][x] = 'd';
			}
			x++;
		}
		x = game->player->position.x - 1;
		y++;
	}
}
