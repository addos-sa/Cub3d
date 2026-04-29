/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:49:21 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/27 11:09:31 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	calculate_for_dda(t_cub3D *game, t_ray *ray, t_DDA *info)
{
	info->hit = 0;
	if (ray->cos_a < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (game->player->position.x - info->map_x)
			* info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - game->player->position.x)
			* info->delta_dist_x;
	}
	if (ray->sin_a < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (game->player->position.y - info->map_y)
			* info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - game->player->position.y)
			* info->delta_dist_y;
	}
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

void	wall_loop(t_cub3D *game, t_DDA *info)
{
	while (info->hit == 0)
	{
		if (info->side_dist_x < info->side_dist_y)
		{
			info->side_dist_x += info->delta_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->side_dist_y += info->delta_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (is_wall(game, info->map_x, info->map_y))
			info->hit = 1;
	}
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

void	set_wall_texture(t_cub3D *game, t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->cos_a > 0)
			game->ac_text = game->textures->east_t;
		else
			game->ac_text = game->textures->west_t;
	}
	else
	{
		if (ray->sin_a > 0)
			game->ac_text = game->textures->south_t;
		else
			game->ac_text = game->textures->north_t;
	}
}
