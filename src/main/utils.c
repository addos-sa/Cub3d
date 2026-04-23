/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:08:45 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/23 10:55:43 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_image(t_cub3D *game)
{
	if (!game)
		return ;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img)
        return ((void)bad_init(game, 5));
    mlx_image_to_window(game->mlx, game->img, 0, 0);
	return ;
}

// int	get_color_hex(char *rgb_str)
// {
// 	char	**rgb;
// 	int		r;
// 	int		g;
// 	int		b;
// 	int		hex_color;
// 	int		i;

// 	rgb = ft_split(rgb_str, ',');
// 	if (!rgb)
// 		return (0);
// 	r = ft_atoi(rgb[0]);
// 	g = ft_atoi(rgb[1]);
// 	b = ft_atoi(rgb[2]);
// 	hex_color = (r << 16) | (g << 8) | b;
// 	i = 0;
// 	while (rgb[i])
// 	{
// 		free(rgb[i]);
// 		i++;
// 	}
// 	free(rgb);
// 	return (hex_color);
// }

t_ray	*create_ray(double start_x, t_cub3D *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->cos_a = cos(start_x) * 0.05;
	ray->sin_a = sin(start_x) * 0.05;
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
