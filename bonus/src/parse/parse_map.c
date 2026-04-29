/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:00:00 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/27 11:06:53 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static char	*get_padded_row(char *original, int width)
{
	char	*padded;
	int		j;

	padded = malloc(sizeof(char) * (width + 1));
	if (!padded)
		return (NULL);
	j = 0;
	while (original[j])
	{
		padded[j] = original[j];
		j++;
	}
	while (j < width)
	{
		padded[j] = ' ';
		j++;
	}
	padded[width] = '\0';
	return (padded);
}

static int	pad_grid(t_cub3D *game)
{
	int		i;
	char	*padded_row;

	i = 0;
	while (i < game->screen->height)
	{
		padded_row = get_padded_row(game->screen->grid[i], game->screen->width);
		if (!padded_row)
			return (1);
		free(game->screen->grid[i]);
		game->screen->grid[i] = padded_row;
		i++;
	}
	return (0);
}

static void	calculate_limits(t_cub3D *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->screen->grid[i])
	{
		j = 0;
		while (game->screen->grid[i][j])
		{
			j++;
		}
		if (j > game->screen->width)
			game->screen->width = j;
		i++;
	}
	game->screen->height = i;
}

static char	**extract_grid(char **file, int start)
{
	int		count;
	int		i;
	char	**grid;

	count = 0;
	while (file[start + count])
		count++;
	grid = malloc(sizeof(char *) * (count + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < count)
	{
		grid[i] = ft_strdup(file[start + i]);
		if (!grid[i])
			return (NULL);
		i++;
	}
	grid[count] = NULL;
	return (grid);
}

int	parse_map(t_cub3D *game, int fd, char *map_path)
{
	char	**file;
	int		i;

	file = get_map(fd, map_path);
	if (!file)
		return (1);
	i = 0;
	if (parse_paths(game, file, &i) != 0)
		return (free_file(file, 1));
	while (file[i] && is_empty_line(file[i]))
		i++;
	if (!file[i])
		return (free_file(file, 2));
	game->screen->grid = extract_grid(file, i);
	free_file(file, 0);
	if (!game->screen->grid)
		return (1);
	calculate_limits(game);
	if (pad_grid(game) != 0)
		return (1);
	return (0);
}
