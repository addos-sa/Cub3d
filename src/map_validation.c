/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:00:00 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/11 12:15:02 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

int	parse_element_line(t_cub3D *game, char *line)
{
	char	*trim;

    trim = skip_spaces(line);
	if (ft_strncmp(trim, "NO ", 3) == 0)
		game->textures->n_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "SO ", 3) == 0)
		game->textures->so_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "WE ", 3) == 0)
		game->textures->w_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "EA ", 3) == 0)
		game->textures->e_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "F ", 2) == 0)
		game->screen->floor_path = ft_strtrim(trim + 2, " \t\n");
	else if (ft_strncmp(trim, "C ", 2) == 0)
		game->screen->ceiling_path = ft_strtrim(trim + 2, " \t\n");
	else
		return (0);
	return (1);
}

int	validate_parsed_data(t_cub3D *game)
{
    if (!game->textures->n_path || !game->textures->so_path
        || !game->textures->w_path || !game->textures->e_path)
        return (printf("Error\n Missing texture path\n"), 1);
    if (!game->screen->floor_path || !game->screen->ceiling_path)
        return (printf("Error\n Missing color definition\n"), 1);
    if (validate_texture_files(game->textures) != 0)
        return (1);
    if (validate_colors(game->screen) != 0)
        return (1);
    if (!game->screen->grid)
        return (printf("Error\n No map found\n"), 1);
    if (validate_map(game) != 0)
        return (1);
    return (0);
}

static int	all_elements_found(t_cub3D *game)
{
    return (game->textures->n_path && game->textures->so_path
        && game->textures->w_path && game->textures->e_path
        && game->screen->floor_path && game->screen->ceiling_path);
}

static int	count_map_lines(t_cub3D *game, int fd, char *first_line)
{
    char	*line;
    int		count;

    (void)game;
    count = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (!is_empty_line(line))
            count++;
        free(line);
    }
    (void)first_line;
    return (count);
}

static char	**append_line(char **grid, int count, char *line)
{
    char	**new_grid;
    int		i;

    new_grid = malloc(sizeof(char *) * (count + 2));
    if (!new_grid)
        return (NULL);
    i = 0;
    while (i < count)
    {
        new_grid[i] = grid[i];
        i++;
    }
    new_grid[count] = line;
    new_grid[count + 1] = NULL;
    free(grid);
    return (new_grid);
}

static int	store_map_line(t_cub3D *game, char *line, int *count)
{
    int		len;
    char	*dup;

    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
    dup = ft_strdup(line);
    if (!dup)
        return (1);
    game->screen->grid = append_line(game->screen->grid, *count, dup);
    if (!game->screen->grid)
        return (1);
    (*count)++;
    return (0);
}

int	parse_file(t_cub3D *game, int fd)
{
    char	*line;
    int		map_lines;
    int		in_map;

    map_lines = 0;
    in_map = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (!in_map && is_empty_line(line))
        {
            free(line);
            continue ;
        }
        if (!in_map && !all_elements_found(game))
        {
            if (!parse_element_line(game, line))
            {
                printf("Error\n Invalid line before map: %s", line);
                return (free(line), 1);
            }
        }
        else
        {
            in_map = 1;
            if (!is_empty_line(line))
            {
                if (store_map_line(game, line, &map_lines) != 0)
                    return (free(line), 1);
            }
        }
        free(line);
    }
    if (!all_elements_found(game))
        return (printf("Error\n Missing element definitions\n"), 1);
    if (map_lines == 0)
        return (printf("Error\n No map found\n"), 1);
    return (0);
}

// static int last_row(char **grid)
// {
// 	int row;

// 	row = 0;
// 	while(grid[row])
// 		row++;
// 	return (row);
// }

// static int	check_walls(t_cub3D *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->screen->m_width)
// 	{
// 		if ((game->screen->grid[0][i] != '1')
// 		|| (game->screen->grid[game->screen->m_height - 1][i] != '1'))
// 			return (0);
// 		i++;
// 	}
// 	j = 0;
// 	while (j < game->screen->m_height)
// 	{
// 		if ((game->screen->grid[j][0] != '1')
// 			|| (game->screen->grid[j][game->screen->m_width - 1] != '1'))
// 			return (0);
// 		j++;
// 	}
// 	return (1);
// }

// static int	check_elements2(t_cub3D *game, int i, int j)
// {
// 	if (game->screen->grid[i][j] == 'P')
// 	{
// 		game->screen->n_player++;
// 		game->player->position.x = j;
// 		game->player->position.y = i;
// 	}
// 	if (game->screen->grid[i][j] != '0' &&
// 		game->screen->grid[i][j] != '1' &&
// 		game->screen->grid[i][j] != 'P' &&
// 		game->screen->grid[i][j] != 'E' &&
// 		game->screen->grid[i][j] != 'C')
// 		return (0);
// 	return (1);
// }

// static int	check_elements(t_cub3D *game)
// {
// 	int	i;
// 	int	j;

// 	game->screen->n_player = 0;
// 	i = 0;
// 	while (i < game->screen->m_height)
// 	{
// 		j = 0;
// 		while (j < game->screen->m_width)
// 		{
// 			if (check_elements2(game, i, j) == 0)
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (game->screen->n_player != 1)
// 		return (0);
// 	return (1);
// }

int map_validation(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		j = jump_lspaces(grid, i, j);
		if (i == 0 || i == last_row(grid) - 1)
		{
			while (grid[i][j])
			{
				if ((grid[i][j] == '1' || grid[i][j] == ' ') && grid[i][j])
					j++;
				else
					return (0);
			}
		}
		else
		{
			if (grid[i][j] == '1' || grid[i][j] == ' ');
		}
		i++;
	}
}
//this will not work, try another method for map_validation (Alan's method on his cub3d)