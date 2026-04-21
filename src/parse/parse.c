/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:58:28 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/21 11:09:57 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

static int	check_file_existence(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		printf("Error\n File <%s> does not exist or cannot be opened\n",
			map_path);
	return (fd);
}

static int set_textures(t_cub3D *game)
{
	game->textures->north_t = mlx_load_png(game->textures->n_path);
	game->textures->south_t = mlx_load_png(game->textures->s_path);
	game->textures->west_t = mlx_load_png(game->textures->w_path);
	game->textures->east_t = mlx_load_png(game->textures->e_path);

	if (!game->textures->north_t || !game->textures->south_t ||
		!game->textures->west_t || !game->textures->east_t)
	{
		printf("Error\nFailed to load textures\n");
		return (1);
	}
	return (0);
}

static void set_parsed_colors(t_cub3D *game)
{
	game->screen->rgb_floor = get_color_value(game->screen->floor_path);
	game->screen->rgb_ceiling = get_color_value(game->screen->ceiling_path);
	return ;
}

int	parse(t_cub3D *game, char *map_path)
{
	int	fd;

	if (!check_file_type(map_path))
	{
		printf("Error\n Map is not a .cub file\n");
		return (1);
	}
	fd = check_file_existence(map_path);
	if (fd < 0)
		return (1);
	if (parse_map(game, fd, map_path))
		return (1);
	if (parse_player(game))
		return (1);
	if (validate_parsed_data(game))
		return (1);
	if (set_textures(game))
		return (1);
	set_parsed_colors(game);
	game->game_running = true;
	return (0);
}
