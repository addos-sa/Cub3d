/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:08:59 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:30 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

static void	draw_pixel(t_cub3D *game, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 20)
	{
		while (x < 20)
		{
			pixeling(start_x + x, start_y + y, color, game);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_minimap_shavings(t_cub3D *game, int x, int y)
{
	x = (int)(game->player->position.x * 20) - 10;
	y = (int)(game->player->position.y * 20) - 10;
	draw_pixel(game, x, y, 0xD93816);
}

void	draw_minimap(t_cub3D *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->screen->grid[y] != NULL)
	{
		while (game->screen->grid[y][x] != '\0')
		{
			if (game->screen->grid[y][x] == '1')
				draw_pixel(game, x * 20, y * 20, 0x000000);
			else if (game->screen->grid[y][x] == 'D')
				draw_pixel(game, x * 20, y * 20, 0x27E3D3);
			else if (game->screen->grid[y][x] == '0'
				|| ft_strchr("NSWE", game->screen->grid[y][x])
				|| ft_strchr("Dd", game->screen->grid[y][x]))
				draw_pixel(game, x * 20, y * 20, 0xE8D8D5);
			x++;
		}
		x = 0;
		y++;
	}
	draw_minimap_shavings(game, x, y);
}
