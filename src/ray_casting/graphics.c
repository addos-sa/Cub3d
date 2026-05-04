/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:14 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/04 10:37:29 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	draw_back(t_cub3D *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				mlx_put_pixel(game->img, x, y, game->screen->rgb_ceiling);
			else
				mlx_put_pixel(game->img, x, y, game->screen->rgb_floor);
			x++;
		}
		y++;
	}
}

bool	touch_wall(double ray_x, double ray_y, t_cub3D *game)
{
	int	x;
	int	y;

	x = (int)ray_x;
	y = (int)ray_y;
	if (x < 0 || y < 0 || x >= game->screen->width
		|| y >= game->screen->height)
		return (1);
	if (game->screen->grid[y][x] == '1')
		return (1);
	return (0);
}

int	text_to_color(t_cub3D *game, int tex_x, int tex_y)
{
	int				index;
	int				color;
	mlx_texture_t	*tex;

	tex = game->ac_text;
	if (!tex || !tex->pixels)
		return (0xFF00FFFF);
	if (tex_x < 0 || (uint32_t)tex_x >= tex->width
		|| tex_y < 0 || (uint32_t)tex_y >= tex->height)
		return (0);
	index = (tex_y * tex->width + tex_x) * 4;
	color = (tex->pixels[index] << 16)
		| (tex->pixels[index + 1] << 8)
		| (tex->pixels[index + 2]);
	return (color);
}
