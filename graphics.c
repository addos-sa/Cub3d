/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:14 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/08 15:04:05 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixeling(int x, int y, int color, t_cub3D *game)
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
	if (x < 0 || y < 0 || x >= game->screen->m_width
		|| y >= game->screen->m_height)
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

void	draw_columm(t_cub3D *game, int i, double height, int tex_x)
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

void	put_pixel(t_cub3D *game, double ray_x, double ray_y, int i)
{
	double	dist;
	double	height;
	int		text_x;

	dist = fix_dist(game, ray_x - game->player->pos->x,
		ray_y - game->player->pos->y);
	if (dist <= 0)
		dist = 0.0001;
	height = HEIGHT / dist;
	text_x = (int)((ray_x + ray_y) * 64) % 64;
	draw_columm(game, i, height, text_x);
}

void	draw_line(t_cub3D *game, int i, double start_x)
{
	double	dist_traveled;
	double	cos_angle;
	double	sin_angle;
	double	ray_x;
	double	ray_y;

	dist_traveled = 0;
	cos_angle = cos(start_x) * 0.05;
	sin_angle = sin(start_x) * 0.05;
	ray_x = game->player->pos->x;
	ray_y = game->player->pos->y;
	while (!touch_wall(ray_x, ray_y, game) && dist_traveled < 20.00)
	{
		ray_x += cos_angle;
		ray_y += sin_angle;
		dist_traveled += 0.05;
	}
	game->ac_text = wl_text(game, ray_x, ray_y, start_x);
	put_pixel(game, ray_x, ray_y, i);
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
