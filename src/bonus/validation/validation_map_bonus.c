/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:52:50 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 09:44:18 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

static int	char_invalid_character(t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			if (screen->grid[i][j] != '0' && screen->grid[i][j] != '1' &&
					screen->grid[i][j] != 'N' && screen->grid[i][j] != 'S' &&
					screen->grid[i][j] != 'E' && screen->grid[i][j] != 'W' &&
					screen->grid[i][j] != 'D' && screen->grid[i][j] != ' ' &&
					screen->grid[i][j] != '\n' && screen->grid[i][j] != '\0')
			{
				printf("Error\n Invalid character in coordinates (%d, %d)\n",
					i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D');
}

static int	check_cell_surrounded(t_screen *screen, int i, int j)
{
	if (i == 0 || i == screen->height - 1 || j == 0 || j == screen->width - 1)
	{
		printf("Error\n Walkable cell at border (%d, %d) - the map is open\n",
			i, j);
		return (0);
	}
	if (is_space_or_empty(screen->grid[i - 1][j]) ||
		is_space_or_empty(screen->grid[i + 1][j]) ||
		is_space_or_empty(screen->grid[i][j - 1]) ||
		is_space_or_empty(screen->grid[i][j + 1]))
	{
		printf("Error\n Walkable cell at (%d, %d) has space/empty neighbor\n",
			i, j);
		return (0);
	}
	return (1);
}

static int	check_walkable_cells(t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			if (is_walkable(screen->grid[i][j]))
			{
				if (!check_cell_surrounded(screen, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map(t_screen *screen)
{
	if (char_invalid_character(screen) != 0)
		return (1);
	if (check_walkable_cells(screen) != 0)
		return (1);
	return (0);
}
