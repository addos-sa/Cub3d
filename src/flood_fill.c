/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:36 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/25 18:25:06 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	flood_fill(t_cub3D *game, int x, int y, int *counters)
{
	if (x < 0 || y < 0 || x >= game->screen->m_width || y >= game->screen->m_height)
		return ;
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'V')
		return ;
	if (game->map_copy[y][x] == 'C')
		counters[0]++;
	if (game->map_copy[y][x] == 'E')
		counters[1] = 1;
	game->map_copy[y][x] = 'V';
	flood_fill(game, x + 1, y, counters);
	flood_fill(game, x - 1, y, counters);
	flood_fill(game, x, y + 1, counters);
	flood_fill(game, x, y - 1, counters);
}

static char	**copy_map(t_cub3D *game, char **map_copy, int i)
{
	while (i < game->screen->m_height)
	{
		map_copy[i] = ft_strdup(game->screen->grid[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (0);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	check_path(t_cub3D *game)
{
	int		i;
	int		counters[1];

	if (game->screen->m_width <= 0 || game->screen->m_height <= 0)
		return (0);
	game->map_copy = (char **)malloc((game->screen->m_height + 1) * sizeof(char *));
	if (!game->map_copy)
		return (0);
	i = 0;
	game->map_copy = copy_map(game, game->map_copy, i);
	flood_fill(game, game->player->position.x, game->player->position.y, counters);
	free_map(game->map_copy);
	if (counters[0] != 1)
		return (0);
	return (1);
}
