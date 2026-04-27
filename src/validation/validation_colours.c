/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:33:05 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/27 11:11:49 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	separate_numbers(const char **str, int *out)
{
	int			val;
	const char	*s;
	int			digits;

	s = skip_spaces(*str);
	if (!s || (*s < '0' || *s > '9'))
		return (1);
	val = 0;
	digits = 0;
	while (*s >= '0' && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		s++;
		digits++;
	}
	if (digits == 0 || val < 0 || val > 255)
		return (1);
	*out = val;
	*str = s;
	return (0);
}

static int	validate_colour_path(const char *str)
{
	int	r;
	int	g;
	int	b;

	if (!str)
		return (1);
	if (separate_numbers(&str, &r))
		return (1);
	str = skip_spaces(str);
	if (*str != ',')
		return (1);
	str++;
	if (separate_numbers(&str, &g))
		return (1);
	str = skip_spaces(str);
	if (*str != ',')
		return (1);
	str++;
	if (separate_numbers(&str, &b))
		return (1);
	str = skip_spaces(str);
	if (*str != '\0' && *str != '\n')
		return (1);
	return (0);
}

int	validate_colours(t_paths *paths)
{
	if (!paths)
		return (1);
	if (!paths->floor_path)
	{
		ft_putendl_fd("Error\nMissing Floor color definition path", 2);
		return (1);
	}
	if (!paths->ceiling_path)
	{
		ft_putendl_fd("Error\nMissing Ceiling color definition path", 2);
		return (1);
	}
	if (validate_colour_path(paths->floor_path))
	{
		ft_putendl_fd("Error\nInvalid Floor string must be RGB", 2);
		return (1);
	}
	if (validate_colour_path(paths->ceiling_path))
	{
		ft_putendl_fd("Error\nInvalid Ceiling string must be RGB", 2);
		return (1);
	}
	return (0);
}
