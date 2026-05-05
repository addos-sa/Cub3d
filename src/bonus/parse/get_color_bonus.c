/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:36:17 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:52 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

static int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	free_rgb_array(char **rgb)
{
	int	i;

	i = 0;
	if (!rgb)
		return ;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

int	get_color_hex(char *rgb_str)
{
	char	**rgb;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	int		hex_color;

	if (!rgb_str)
		return (0);
	rgb = ft_split(rgb_str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_rgb_array(rgb);
		return (0);
	}
	r = (uint8_t)ft_atoi(rgb[0]);
	g = (uint8_t)ft_atoi(rgb[1]);
	b = (uint8_t)ft_atoi(rgb[2]);
	hex_color = get_rgba(r, g, b, 255);
	free_rgb_array(rgb);
	return (hex_color);
}
