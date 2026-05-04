/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:08:45 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/04 10:36:12 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	get_color_value(char *str)
{
	int	r;
	int	g;
	int	b;

	while (*str == ' ' || *str == '\t')
		str++;
	r = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	g = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	b = ft_atoi(str);
	return ((r << 16) | (g << 8) | b);
}

t_ray	*create_ray(double start_x, t_cub3D *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->cos_a = cos(start_x);
	ray->sin_a = sin(start_x);
	ray->ray_x = game->player->position.x;
	ray->ray_y = game->player->position.y;
	ray->wall_hit = 0.00;
	return (ray);
}

char	*skip_spaces(const char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return ((char *)s);
}

int	is_empty_line(char *line)
{
	const char	*trimmed;

	trimmed = skip_spaces(line);
	return (*trimmed == '\0' || *trimmed == '\n');
}

int	is_space_or_empty(char c)
{
	return (c == ' ' || c == '\0' || c == '\n');
}
