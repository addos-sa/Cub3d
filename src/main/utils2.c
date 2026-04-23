/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:36:17 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/23 11:17:37 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_hex(char *rgb_str)
{
    char	**rgb;
    uint8_t	r;
    uint8_t	g;
    uint8_t	b;
    int		hex_color;
    int		i;

	i = 0;
    if (!rgb_str)
        return (0);
    rgb = ft_split(rgb_str, ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		while (rgb[i])
    	{
        	free(rgb[i]);
        	i++;
    	}
        return (0);
	}
    r = (uint8_t)ft_atoi(rgb[0]);
    g = (uint8_t)ft_atoi(rgb[1]);
    b = (uint8_t)ft_atoi(rgb[2]);
    hex_color = get_rgba(r, g, b, 255);
    i = 0;
    while (rgb[i])
    {
        free(rgb[i]);
        i++;
    }
    free(rgb);
    return (hex_color);
}
