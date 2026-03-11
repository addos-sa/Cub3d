/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:04 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/27 09:33:19 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	bad_arg(int argc)
{
	if (argc > 0)
	{
		if (argc == 1)
			return (ft_printf("Error\nNo map sent, try './cub3D <map.cub>'\n"), 1);
		else
		{
			return (ft_printf("Error\nToo many arguments sent, try \
				'./cub3D <map.cub>'\n"), 1);
		}
	}
	else
		return (ft_printf("Error\nMap sent is empty\n"), 1);
}

int	main(int argc, char **argv)
{
	t_cub3D	game;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (bad_arg(0));
		game = init_game(argv[1], &game);
		if (game.game_running)
		{
			mlx_key_hook(game.mlx, /*&key_hook*/, &game);
			mlx_close_hook(game.mlx, /*close_hook*/, &game);
			mlx_loop_hook(game.mlx, /*&loop_hook*/, &game);
			mlx_loop(game.mlx);
		}
		if (game.mlx)
			mlx_terminate(game.mlx);
	}
	else
		return (bad_arg(argc));
	//allocate memory to struct
	//check if memory allocated
	//initialize struct
	//allocate memory to textures
	//check if memory allocated
	//initialize textures
	return (0);
}
