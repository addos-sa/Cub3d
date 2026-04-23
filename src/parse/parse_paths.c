/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:25:21 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/21 11:33:39 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	all_paths_found(t_cub3D *game)
{
	return (game->paths->n_path && game->paths->s_path
		&& game->paths->w_path && game->paths->e_path
		&& game->paths->floor_path && game->paths->ceiling_path);
}

static int	parse_path_line(t_cub3D *game, char *line)
{
	char	*trim;

	trim = skip_spaces(line);
	if (ft_strncmp(trim, "NO ", 3) == 0)
		game->paths->n_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "SO ", 3) == 0)
		game->paths->s_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "WE ", 3) == 0)
		game->paths->w_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "EA ", 3) == 0)
		game->paths->e_path = ft_strtrim(trim + 3, " \t\n");
	else if (ft_strncmp(trim, "F ", 2) == 0)
		game->paths->floor_path = ft_strtrim(trim + 2, " \t\n");
	else if (ft_strncmp(trim, "C ", 2) == 0)
		game->paths->ceiling_path = ft_strtrim(trim + 2, " \t\n");
	else
		return (0);
	return (1);
}

int	parse_paths(t_cub3D *game, char **file, int *i)
{
	while (file[*i] && !all_paths_found(game))
	{
		if (is_empty_line(file[*i]))
		{
			(*i)++;
			continue ;
		}
		if (!parse_path_line(game, file[*i]))
		{
			printf("Error\n Invalid line: %s\n", file[*i]);
			return (1);
		}
		(*i)++;
	}
	if (!all_paths_found(game))
	{
		printf("Error\n Missing some or all path definitions\n");
		return (1);
	}
	return (0);
}
