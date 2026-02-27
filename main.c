/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:15:22 by addos-sa          #+#    #+#             */
/*   Updated: 2026/02/25 15:06:35 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_cub3D *game)
{
	
}

int	main(int argc, char **argv)
{
	t_cub3D	*cub3d;
	
	if (argc != 2)
		return (1);
	/* if (pars() != 0)
	{
		return (0);
	}*/
	cub3d = malloc(sizeof(t_cub3D));
	ini_game(cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
