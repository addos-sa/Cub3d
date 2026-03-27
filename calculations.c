/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:49:21 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/24 12:13:49 by addos-sa         ###   ########.fr       */
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
