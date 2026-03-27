/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:08:45 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/20 13:45:55 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

const char	*skip_spaces(const char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return (s);
}

int	is_empty_line(char *line)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	return (*trimmed == '\0' || *trimmed == '\n');
}

int	is_space_or_empty(char c)
{
	return (c == ' ' || c == '\0' || c == '\n');
}
