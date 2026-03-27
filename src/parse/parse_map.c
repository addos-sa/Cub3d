/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:00:00 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/19 11:08:03 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

static void	free_file(char **file)
{
	int	i;

	if (!file)
		return ;
	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
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
	{
		free_file(file);
		return (1);
	}
	while (file[i] && is_empty_line(file[i]))
		i++;
	if (!file[i])
	{
		printf("Error\n No map found\n");
		free_file(file);
		return (1);
	}
	game->screen->grid = extract_grid(file, i);
	free_file(file);
	if (!game->screen->grid)
		return (1);
	return (0);
}
