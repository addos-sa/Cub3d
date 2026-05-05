/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:24:06 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 09:44:12 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

int	validate_parsed_data(t_cub3D *game)
{
	if (validate_texture_files(game->paths))
		return (1);
	if (validate_colours(game->paths))
		return (1);
	if (!game->screen->grid)
		return (printf("Error\n No map found\n"), 1);
	if (validate_map(game->screen) != 0)
		return (1);
	return (0);
}
