/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:00:05 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/15 13:13:42 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	pixeling(int x, int y, int color, t_cub3D *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = (y * game->img->width + x) * 4;
	game->img->pixels[index] = (color >> 16) & 0xFF; // R
	game->img->pixels[index + 1] = (color >> 8)  & 0xFF; // G
	game->img->pixels[index + 2] = color & 0xFF; // B
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

static void	put_pixel(t_cub3D *game, t_ray *ray, int i)
{
	double	dist;
	double	height;
	int		text_x;

	dist = fix_dist(game, ray->ray_x - game->player->position.x,
		ray->ray_y - game->player->position.y);
	if (dist <= 0)
		dist = 0.0001;
	height = HEIGHT / dist;
	text_x = (int)(ray->wall_hit * 64.00);
	draw_columm(game, i, height, text_x);
}

static void	draw_line(t_cub3D *game, int i, double start_x)
{
	double	dist_traveled;
	t_ray	*ray;
	int		side;

	dist_traveled = 0;
	ray = create_ray(start_x, i, game);
	while (!touch_wall(ray->ray_x,ray->ray_y, game) && dist_traveled < 20.00)
	{
		ray->ray_x += ray->cos_a;
		ray->ray_y += ray->sin_a;
		dist_traveled += 0.05;
	}
	if (!touch_wall(ray->ray_x - ray->cos_a, ray->ray_y, game))
		side = 0;
	else
		side = 1;
	if (side == 0)
		ray->wall_hit = ray->ray_y - floor(ray->ray_y);
	else
		ray->wall_hit = ray->ray_x - floor(ray->ray_x);
	set_wall_texture(game, ray, side);
	put_pixel(game, ray, i);
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
	while(i < WIDTH)
	{
		draw_line(game, i, start_x);
		start_x += fraction;
		i++;
	}
	//puede que haya que hacer algo mas
	return (0);
}
