/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:44:08 by albocoq           #+#    #+#             */
/*   Updated: 2026/03/10 18:55:29 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_commands(char *filename)
{
	int		i;
	char	**file;

	if (!filename || !*filename)
		return (printf("Error\n File not exist or cannot open.\n"), 1);
	file = ft_split(filename, '.');
	i = 0;
	if (!file)
	{
		printf("Error\n Unable to split filename.\n");
		i = 1;
	}
	else if (!file[1])
	{
		printf("Error\n Invalid file format: <%s>.cub\n", filename);
		i = 1;
	}
	else if (ft_strcmp(file[1], "cub") != 0)
	{
		printf("Error\n Invalid file format: <%s>.cub\n", filename);
		i = 1;
	}
	free_splits(file);
	return (i);
}

static int	check_existence_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		printf("Error\n File <%s> does not exist or cannot be opened.\n",
			filename);
	return (fd);
}

int	global_check(char *filename, t_map *map)
{
	int	fd;

	init_map_elements(map);
	if (check_commands(filename) != 0)
		return (1);
	fd = check_existence_file(filename);
	if (fd < 0)
		return (1);
	if (init_map(map, fd) != 0)
	{
		get_next_line(-1);
		close(fd);
		return (1);
	}
	if (check_inputs(map) != 0 || check_colors(&map->elements) != 0)
	{
		get_next_line(-1);
		close(fd);
		return (1);
	}
	if (fd > 0)
		close(fd);
	get_next_line(-1);
	return (0);
}

void	init_map_elements(t_map *map)
{
	map->mat.width = 0;
	map->mat.height = 0;
	map->mat.mat = NULL;
	map->elements.no = NULL;
	map->elements.so = NULL;
	map->elements.we = NULL;
	map->elements.ea = NULL;
	map->elements.f = NULL;
	map->elements.c = NULL;
}
