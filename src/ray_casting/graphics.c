/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:14 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/15 11:35:17 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	fix_dist(t_cub3D *game, double delta_x, double delta_y)
{
	double	angle;
	double	fix_dist;

	angle = atan2(delta_y, delta_x) - game->player->angle;
	fix_dist = pythagoras(delta_x, delta_y) * cos(angle);
	return (fix_dist);
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
	if (tex_x < 0 || (uint32_t)tex_x >= tex->width || 
		tex_y < 0 || (uint32_t)tex_y >= tex->height)
		return (0);
	index = (tex_y * tex->width + tex_x) * 4;
	color = (tex->pixels[index] << 16)
		| (tex->pixels[index + 1] << 8)
		| (tex->pixels[index + 2]);
	return (color);
}
