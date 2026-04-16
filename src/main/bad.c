/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:06:08 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/16 12:44:34 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void bad_game()
{
	
}

char bad_init(t_cub3D *game, int part)
{
	if (part = 1)
	{
		printf("Error\nScreen memory allocation failed");
		free(game);
		return (NULL);
	}
	if (part = 2)
	{
		printf("Error\nTextures memory allocation failed");
		free(game);
		free(game->screen);
		return (NULL);
	}
	if (part = 3)
	{
		printf("Error\nPlayer memory allocation failed");
		free(game);
		free(game->screen);
		free(game->textures);
		return (NULL);
	}
}

int	bad_arg(int argc)
{
	if (argc > 0)
	{
		if (argc == 1)
		{
			ft_printf("Error\nNo map sent, try './cub3D <map.cub>'\n");
			return (1);
		}
		else
		{
			ft_printf("Error\nToo many arguments sent, try \
				'./cub3D <map.cub>'\n");
			return (1);
		}
	}
	else
	{
		ft_printf("Error\nMap sent is empty\n");
		return (1);
	}
}