/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:04 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/16 14:51:47 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void free_game(t_cub3D *game, int level)
{
	
}

static void	close_handler(void *param)
{
	t_cub3D	*game;

	game = (t_cub3D *)param;
	free_game(game, 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_cub3D	*game;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (bad_arg(0));
		game = init_game(game);
		if (parse(game, argv[1]))
			return (1);
		game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
		if (!game->mlx)
			free_game(game, 1);
		if (game->game_running)
		{
			mlx_close_hook(game->mlx, &close_handler, &game);
			mlx_loop_hook(game->mlx, &game_loop, &game);
			mlx_loop(game->mlx);
		}
		if (game->mlx)
			mlx_terminate(game->mlx);
	}
	else
		return (bad_arg(argc));
	return (0);
}
