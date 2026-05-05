/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:06:08 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 09:43:35 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

int	bad_game(int i)
{
	printf("Error\nGame memory allocation failed");
	return (i);
}

static void	bad_init2(t_cub3D *game, int part)
{
	if (part == 4)
	{
		printf("Error\nPath memory allocation failed");
		free(game);
		free(game->screen);
		free(game->textures);
		free(game->player);
	}
	if (part == 5)
	{
		printf("Error\nImage memory allocation failed");
		free(game);
		free(game->screen);
		free(game->textures);
		free(game->player);
		free(game->paths);
	}
	return ;
}

void	*bad_init(t_cub3D *game, int part)
{
	if (part == 1)
	{
		printf("Error\nScreen memory allocation failed");
		free(game);
	}
	if (part == 2)
	{
		printf("Error\nTextures memory allocation failed");
		free(game);
		free(game->screen);
	}
	if (part == 3)
	{
		printf("Error\nPlayer memory allocation failed");
		free(game);
		free(game->screen);
		free(game->textures);
	}
	if (part > 3)
		bad_init2(game, part);
	return (NULL);
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
