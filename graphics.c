/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:14 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/06 12:43:49 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_cub3D *game, int i, float start_x)
{
	
}

int	draw_loop(t_cub3D *game)
{
	int			i;
	float		fraction;
	float		start_x;

	i = 0;
	fraction = PI / 3 / WIDTH;
	start_x = game->player->angle - PI / 6;
	while(i < WIDTH)
	{
		draw_line(game, i, start_x);
		start_x += fraction;
		i++;
	}
}
