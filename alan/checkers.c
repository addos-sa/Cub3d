/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:45:26 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/25 15:43:49 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_elements(t_elements *elements, int i)
{
	const char	*paths[4];
	int			fd;

	paths[0] = elements->no;
	paths[1] = elements->so;
	paths[2] = elements->we;
	paths[3] = elements->ea;
	while (i < 4)
	{
		if (!paths[i] || paths[i][0] == '\0')
		{
			printf("Error\n Texture path is missing.\n");
			return (1);
		}
		fd = open(paths[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error\n Texture file <%s> does not exist.\n", paths[i]);
			return (1);
		}
		close(fd);
		i++;
	}
	return (0);
}

static int	correct_elements_error(int found_pos_player)
{
	if (found_pos_player == 0)
	{
		printf("Error\n No player starting position found in the map.\n");
		return (1);
	}
	else if (found_pos_player > 1)
	{
		printf("Error\n Multiple player start positions found in the map.\n");
		return (1);
	}
	return (0);
}

static int	check_correct_elements(t_mat *mat)
{
	int	i;
	int	j;
	int	found_pos_player;

	i = 0;
	found_pos_player = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			if (mat->mat[i][j] == 'N' || mat->mat[i][j] == 'S' ||
				mat->mat[i][j] == 'E' || mat->mat[i][j] == 'W')
				found_pos_player++;
			j++;
		}
		i++;
	}
	if (correct_elements_error(found_pos_player) != 0)
		return (1);
	return (0);
}

int	check_inputs(t_map *map)
{
	int	i;

	i = 0;
	if (check_elements(&map->elements, i) != 0)
		return (1);
	if (check_mat(&map->mat) != 0)
		return (1);
	if (check_correct_elements(&map->mat) != 0)
		return (1);
	return (0);
}
