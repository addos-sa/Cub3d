/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:24:54 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/16 12:04:42 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	validate_texture_path(char *path)
{
	int	fd;

	if (!path)
	{
		ft_putendl_fd("Error\nTexture path is NULL", 2);
		return (1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open texture file: ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	close(fd);
	return (0);
}

int	validate_texture_files(t_textures *textures)
{
	if (!textures)
		return (1);
	if (validate_texture_path(textures->n_path))
		return (1);
	if (validate_texture_path(textures->s_path))
		return (1);
	if (validate_texture_path(textures->e_path))
		return (1);
	if (validate_texture_path(textures->w_path))
		return (1);
	return (0);
}