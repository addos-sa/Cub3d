/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:55:48 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/11 13:11:30 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
