/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:01:10 by albocoq           #+#    #+#             */
/*   Updated: 2025/12/01 12:38:11 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	char_invalid_character(t_mat *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			if (mat->mat[i][j] != '0' && mat->mat[i][j] != '1' &&
					mat->mat[i][j] != 'N' && mat->mat[i][j] != 'S' &&
					mat->mat[i][j] != 'E' && mat->mat[i][j] != 'W' &&
					mat->mat[i][j] != ' ' && mat->mat[i][j] != '\n' &&
					mat->mat[i][j] != '\0')
			{
				printf("Error\n Invalid character '%c' in map at (%d, %d).\n",
					mat->mat[i][j], i, j);
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
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_cell_surrounded(t_mat *mat, int i, int j)
{
	if (i == 0 || i == mat->height - 1 || j == 0 || j == mat->width - 1)
	{
		printf("Error\n Walkable cell at border (%d, %d) - map not enclosed.\n",
			i, j);
		return (0);
	}
	if (is_space_or_empty(mat->mat[i - 1][j]) ||
		is_space_or_empty(mat->mat[i + 1][j]) ||
		is_space_or_empty(mat->mat[i][j - 1]) ||
		is_space_or_empty(mat->mat[i][j + 1]))
	{
		printf("Error\n Walkable cell at (%d, %d) has space/empty neighbor.\n",
			i, j);
		return (0);
	}
	return (1);
}

static int	check_walkable_cells(t_mat *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			if (is_walkable(mat->mat[i][j]))
			{
				if (!check_cell_surrounded(mat, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_mat(t_mat *mat)
{
	if (char_invalid_character(mat) != 0)
		return (1);
	if (check_walkable_cells(mat) != 0)
		return (1);
	return (0);
}
