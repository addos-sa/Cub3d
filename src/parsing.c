/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:58:28 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/11 12:03:23 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	init_parsing_fields(t_cub3D *game)
{
	game->screen->grid = NULL;
	game->screen->floor_path = NULL;
	game->screen->ceiling_path = NULL;
	game->screen->rgb_floor = 0;
	game->screen->rgb_ceiling = 0;
	game->screen->n_player = 0;
	game->textures->n_path = NULL;
	game->textures->so_path = NULL;
	game->textures->w_path = NULL;
	game->textures->e_path = NULL;
}

static int	check_file_type(char *map_path)
{
	int	len;

	if (!map_path)
		return (0);
	len = ft_strlen(map_path);
	if (len < 4)
		return (0);
	if (map_path[len - 4] == '.'
		&& map_path[len - 3] == 'c'
		&& map_path[len - 2] == 'u'
		&& map_path[len - 1] == 'b')
		return (1);
	return (0);
}

static int	check_existence_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		printf("Error\n File <%s> does not exist or cannot be opened.\n",
			map_path);
	return (fd);
}

int	parsing(char *map_path, t_cub3D *game)
{
	int	fd;

	init_map_elements(game);
	if (!check_file_type(map_path))
	{
		printf("Error\n Map is not a .cub file\n");
		return (1);
	}
	fd = check_existence_file(map_path);
	if (fd < 0)
		return (1);
	if (parse_file(game, fd) != 0)
	{
		get_next_line(-1);
		close(fd);
		return (1);
	}
	if (validate_parsed_data(game) != 0)
	{
		get_next_line(-1);
		close(fd);
		return (1);
	}
	close(fd);
	get_next_line(-1);
	return (0);
}
