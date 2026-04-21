/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:34:10 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/21 10:17:09 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	case_key_pressed(t_cub3D *game, double cos_ang, double sin_ang, int nm)
{
	double	speed;

	speed = 0.05;
	if (nm == 1 || nm == 4)
		game->player->position.x += cos_ang * speed;
	if (nm == 2 || nm == 3)
		game->player->position.x -= cos_ang * speed;
	if (nm == 1 || nm == 3)
		game->player->position.y += sin_ang * speed;
	if (nm == 2 || nm == 4)
		game->player->position.y -= sin_ang * speed;
	
}

static void	which_key(t_cub3D *game, double cf, double sf, double p_y, double p_x)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (!is_wall(game, p_x + cf, p_y + sf))
			case_key_pressed(game, cf, sf, 1);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (!is_wall(game, p_x + cf, p_y + sf))
			case_key_pressed(game, cf, sf, 2);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (!is_wall(game, p_x + cf, p_y + sf))
			case_key_pressed(game, cf, sf, 3);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (!is_wall(game, p_x + cf, p_y + sf))
			case_key_pressed(game, cf, sf, 4);
	}
}

static void	key_pressed(t_cub3D *game)
{
	double	speed;
	double	cos_offset;
	double	sin_offset;
	double	p_x;
	double	p_y;

	speed = 0.50;
	cos_offset = cos(game->player->angle) * speed;
	sin_offset = sin(game->player->angle) * speed;
	p_x = game->player->position.x;
	p_y = game->player->position.y;
	which_key(game, cos_offset, sin_offset, p_y, p_x);
	
}

static void	player_movement(t_cub3D *game)
{
	double	angle_speed;

	angle_speed = 0.03;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player->angle -= angle_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player->angle += angle_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	key_pressed(game);
}

void	game_loop(void *param)
{
	t_cub3D *game;

	game = (t_cub3D *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	player_movement(game);
	ft_memset(game->img->pixels, 0, game->img->width * game->img->height * 4);
	draw_loop(game);
}
