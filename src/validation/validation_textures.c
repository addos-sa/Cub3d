/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:24:54 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/27 11:12:00 by frasanch         ###   ########.fr       */
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

int	validate_texture_files(t_paths *paths)
{
	if (!paths)
		return (1);
	if (validate_texture_path(paths->n_path))
		return (1);
	if (validate_texture_path(paths->s_path))
		return (1);
	if (validate_texture_path(paths->e_path))
		return (1);
	if (validate_texture_path(paths->w_path))
		return (1);
	return (0);
}
