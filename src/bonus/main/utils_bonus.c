/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:08:45 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:49 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

void	init_image(t_cub3D *game)
{
	if (!game)
		return ;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return ((void)bad_init(game, 5));
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	return ;
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
