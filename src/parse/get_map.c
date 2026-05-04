/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:55:48 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/04 10:36:41 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static int	line_counter(int fd)
{
	int		c;
	char	*line;

	c = 0;
	if (fd == -1)
	{
		perror("Error\nCannot access file\n");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		c++;
		free(line);
	}
	close(fd);
	return (c);
}

static char	**get_line(char **map, int fd, int line_count)
{
	char	*line;
	int		c;
	int		len;

	c = 0;
	while (c < line_count)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[c] = ft_strdup(line);
		free(line);
		c++;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	map[c] = NULL;
	return (map);
}

char	**get_map(int fd, char *map_path)
{
	char	**map;
	int		line_count;

	line_count = line_counter(fd);
	if (line_count <= 0)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!map || line_count <= 0)
		return (NULL);
	map = get_line(map, fd, line_count);
	close(fd);
	return (map);
}
