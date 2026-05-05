/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:34:10 by addos-sa          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:44 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

void	key_hook_handler(mlx_key_data_t keydata, void *param)
{
	t_cub3D	*game;

	game = (t_cub3D *)param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		game->player->mouse = !game->player->mouse;
		if (game->player->mouse == 1)
		{
			mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		}
		else
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		game->player->map = !game->player->map;
}

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
	if (game->player->mouse == 1)
		mouse_movement(game);
	ft_memset(game->img->pixels, 0, game->img->width * game->img->height * 4);
	is_there_a_door(game);
	draw_loop(game);
	if (game->player->map == 1)
		draw_minimap(game);
}
