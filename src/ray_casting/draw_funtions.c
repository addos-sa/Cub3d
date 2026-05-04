/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:00:05 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/04 10:37:45 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	pixeling(int x, int y, int color, t_cub3D *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = (y * game->img->width + x) * 4;
	game->img->pixels[index] = (color >> 16) & 0xFF;
	game->img->pixels[index + 1] = (color >> 8) & 0xFF;
	game->img->pixels[index + 2] = color & 0xFF;
	game->img->pixels[index + 3] = 0xFF;
}

static void	draw_columm(t_cub3D *game, int i, double height, int tex_x)
{
	int		y;
	int		end;
	double	step;
	double	tex_pos;
	int		color;

	y = (HEIGHT - height) / 2;
	end = y + height;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	step = 64.0 / height;
	tex_pos = 0;
	if (y < 0)
	{
		tex_pos = -y * step;
		y = 0;
	}
	while (y < end)
	{
		color = text_to_color(game, tex_x, (int)tex_pos & 63);
		tex_pos += step;
		pixeling(i, y, color, game);
		y++;
	}
}

static void	put_pixel(t_cub3D *game, t_ray *ray, int i, double dist)
{
	double	height;
	int		text_x;

	if (dist <= 0)
		dist = 0.0001;
	height = HEIGHT / dist;
	text_x = (int)(ray->wall_hit * 64.00);
	draw_columm(game, i, height, text_x);
}

static void	draw_line(t_cub3D *game, int i, double start_x)
{
	t_ray	*ray;
	t_dda	info;

	ray = create_ray(start_x, game);
	info.map_x = (int)game->player->position.x;
	info.map_y = (int)game->player->position.y;
	info.delta_dist_x = fabs(1.0 / ray->cos_a);
	info.delta_dist_y = fabs(1.0 / ray->sin_a);
	calculate_for_dda(game, ray, &info);
	wall_loop(game, &info);
	if (info.side == 0)
	{
		info.wall_dst = (info.side_dist_x - info.delta_dist_x);
		ray->wall_hit = game->player->position.y + info.wall_dst * ray->sin_a;
	}
	else
	{
		info.wall_dst = (info.side_dist_y - info.delta_dist_y);
		ray->wall_hit = game->player->position.x + info.wall_dst * ray->cos_a;
	}
	ray->wall_hit -= floor(ray->wall_hit);
	set_wall_texture(game, ray, &info);
	put_pixel(game, ray, i, info.wall_dst
		* cos(game->player->angle - start_x));
	free(ray);
}

int	draw_loop(t_cub3D *game)
{
	int			i;
	double		fraction;
	double		start_x;

	i = 0;
	fraction = (PI / 3) / WIDTH;
	start_x = game->player->angle - (PI / 6);
	draw_back(game);
	while (i < WIDTH)
	{
		draw_line(game, i, start_x);
		start_x += fraction;
		i++;
	}
	return (0);
}
