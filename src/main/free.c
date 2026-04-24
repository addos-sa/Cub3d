/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:24:35 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/24 11:23:48 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	free_file(char **file, int type)
{
	int	i;

	if (!file)
		return (1);
	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
	if (type == 2)
		printf("Error\n No map found\n");
	else if (type == 1 || type == 2)
		return (1);
	return (0);
}

static void free_paths(t_cub3D *game)
{
	if (game->paths->n_path)
        	free(game->paths->n_path);
    if (game->paths->s_path)
        	free(game->paths->s_path);
    if (game->paths->e_path)
        	free(game->paths->e_path);
    if (game->paths->w_path)
        	free(game->paths->w_path);
    if (game->paths->floor_path)
        	free(game->paths->floor_path);
    if (game->paths->ceiling_path)
        	free(game->paths->ceiling_path);
}

static void free_textures(t_cub3D *game)
{
	if (game->textures->north_t)
        mlx_delete_texture(game->textures->north_t);
    if (game->textures->south_t)
        mlx_delete_texture(game->textures->south_t);
    if (game->textures->east_t)
        mlx_delete_texture(game->textures->east_t);
    if (game->textures->west_t)
        mlx_delete_texture(game->textures->west_t);
}

static void free_grid(t_cub3D *game)
{
	int i;

	i = 0;
	if (game->screen->grid)
	{
		while (game->screen->grid[i])
		{
			free(game->screen->grid[i]);
			i++;
		}
		free(game->screen->grid);
	}
}

int free_game(t_cub3D *game, int mode)
{
	if (!game)
		return (mode);

	if (game->screen)
	{
		free_grid(game);
		free(game->screen);
	}
	if (game->textures)
	{
		free_textures(game);
		free(game->textures);
	}
	if (game->player)
		free(game->player);
	if (game->paths)
	{
		free_paths(game);
		free(game->paths);
	}
	free(game);
	return (mode);
}
