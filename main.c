/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:15:22 by addos-sa          #+#    #+#             */
/*   Updated: 2026/02/24 15:42:44 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		return (1);
	/* if (pars() != 0)
	{
		return (0);
	}*/
	game = malloc(sizeof(t_game));
	ini_game(game);
	mlx_loop(game->mlx);
	return (0);
}
