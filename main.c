/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:15:22 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/24 11:54:30 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_handler(void *param)
{
	t_cub3D	*game;

	game = (t_cub3D *)param;
	free_game(game);
	exit(0);
}

int	main(int argc, char **argv)//vale limpiar las cosas y ver si funcionan sacando algo por pantalla en otro programa
{
	t_cub3D	*game;
	
	if (argc != 2)
		return (1);
	/* if (pars() != 0)
	{
		return (0);
	}*/
	game = malloc(sizeof(t_cub3D));
	ini_game(game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_close_hook(game->mlx, &close_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
