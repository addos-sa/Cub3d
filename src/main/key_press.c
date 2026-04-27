/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:34:10 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/27 10:58:17 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	apply_movement(t_cub3D *game, double dx, double dy)
{
	double	p_y;
	double	p_x;

	p_x = game->player->position.x;
	p_y = game->player->position.y;
	if (!is_wall(game, p_x + (dx * 10.0), p_y))
		game->player->position.x += dx;
	if (!is_wall(game, p_x, p_y + (dy * 10.0)))
		game->player->position.y += dy;
}

static void	which_key(t_cub3D *game)
{
	double	speed;
	double	angle;

	speed = 0.05;
	angle = game->player->angle;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		apply_movement(game, cos(angle) * speed, sin(angle) * speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		apply_movement(game, -cos(angle) * speed, -sin(angle) * speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		apply_movement(game, -sin(angle) * speed, cos(angle) * speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		apply_movement(game, sin(angle) * speed, -cos(angle) * speed);
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
	which_key(game);
}

void	game_loop(void *param)
{
	t_cub3D	*game;

	game = (t_cub3D *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	player_movement(game);
	ft_memset(game->img->pixels, 0, game->img->width * game->img->height * 4);
	draw_loop(game);
}
