/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:04 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/24 12:14:04 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	check_file_type(char *map_path)
{
	int	len;

	if (!map_path)
		return (0);
	len = ft_strlen(map_path);
	if (len < 4)
		return (0);
	if (map_path[len - 4] == '.'
		&& map_path[len - 3] == 'c'
		&& map_path[len - 2] == 'u'
		&& map_path[len - 1] == 'b')
		return (1);
	return (0);
}

int	bad_arg(int argc)
{
	if (argc == 1)
		return (ft_printf("Error\nNo map sent, try './cub3D <map.cub>'\n"), 1);
	else
		return (ft_printf("Error\nToo many arguments sent, try \
			'./cub3D <map.cub>'\n"), 1);
}

int	main(int argc, char **argv)
{
	t_cub3D	game;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (bad_arg(1));
		game = init_game(argv[1], &game);
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
