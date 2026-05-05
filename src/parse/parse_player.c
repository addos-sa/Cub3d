/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:09:24 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/04 11:50:27 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	count_error(int n_player)
{
	if (n_player == 0)
	{
		printf("Error\n No player starting position found in the map\n");
		return (1);
	}
	else if (n_player > 1)
	{
		printf("Error\n Multiple player start positions found in the map\n");
		return (1);
	}
	return (0);
}

static int	count_player(t_screen *screen, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			if (screen->grid[i][j] == 'N' || screen->grid[i][j] == 'S'
				||screen->grid[i][j] == 'E' || screen->grid[i][j] == 'W')
			{
				player->position.x = j + 0.5;
				player->position.y = i + 0.5;
				screen->n_player++;
			}
			j++;
		}
		i++;
	}
	if (count_error(screen->n_player))
		return (1);
	return (0);
}

int	parse_player(t_cub3D *game)
{
	if (count_player(game->screen, game->player))
		return (1);
	return (0);
}
