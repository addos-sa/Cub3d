/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:49:21 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/08 14:48:00 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pythagoras(double x, double y)
{
	return (sqrt(x * x + y * y));
}

int	is_wall(t_cub3D *game, double pos_x, double pos_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)pos_x;
	map_y = (int)pos_y;
	if (map_x < 0 || map_y < 0)
		return (1);
	if (game->screen->grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

mlx_texture_t	*wl_text(t_cub3D *game, double ray_x, double ray_y, double ang)
{
	double	x_frac;
	double	y_frac;

	x_frac = ray_x - floor(ray_x);
	y_frac = ray_y - floor(ray_y);
	if (y_frac < 0.05 || y_frac > 0.95)
	{
		if (sin(ang) > 0)
			return (game->textures->south_t);
		return (game->textures->north_t);
	}
	if (cos(ang) > 0)
		return (game->textures->east_t);
	return (game->textures->west_t);
}
