/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:34:10 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/06 12:24:51 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == 'w')
		player->k_up = true;
	if (keycode == 's')
		player->k_down = true;
	if (keycode == 'a')
		player->k_left = true;
	if (keycode == 'd')
		player->k_right = true;
	if (keycode == LEFT)
		player->r_left = true;
	if (keycode == RIGHT)
		player->r_right = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{	
	if (keycode == 'w')
		player->k_up = false;
	if (keycode == 's')
		player->k_down = false;
	if (keycode == 'a')
		player->k_left = false;
	if (keycode == 'd')
		player->k_right = false;
	if (keycode == LEFT)
		player->r_left = false;
	if (keycode == RIGHT)
		player->r_right = false;
	return (0);
}

void	key_pressed(t_player *player)
{
	int		speed = 3;
	float	cos_angle = cos(player->angle);
	float	sin_angle = sin(player->angle);
	
	if (player->k_up)
	{
		player->position->x += cos_angle * speed;
		player->position->y += sin_angle * speed;
	}
	if (player->k_down)
	{
		player->position->x -= cos_angle * speed;
		player->position->y -= sin_angle * speed;
	}
	if (player->k_right)
	{
		player->position->x -= sin_angle * speed;
		player->position->y += cos_angle * speed;
	}
	if (player->k_left)
	{
		player->position->x += sin_angle * speed;
		player->position->y -= cos_angle * speed;
	}
}

void	player_movement(t_player *player)
{
	float	angle_speed = 0.03;

	if (player->r_left)
		player->angle -= angle_speed;
	if (player->r_right)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player ->angle < 0)
		player->angle = 2 * PI;
	key_pressed(player);
}
