/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:52:45 by emilgarc          #+#    #+#             */
/*   Updated: 2025/12/01 10:53:31 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const char	*skip_spaces(const char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return (s);
}

static int	parse_number(const char **str, int *out)
{
	int			val;
	const char	*s;
	int			digits;

	s = skip_spaces(*str);
	if (!s || (*s < '0' || *s > '9'))
		return (1);
	val = 0;
	digits = 0;
	while (*s >= '0' && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		s++;
		digits++;
	}
	if (digits == 0 || val < 0 || val > 255)
		return (1);
	*out = val;
	*str = s;
	return (0);
}

static int	validate_rgb_string(const char *str)
{
	int	r;
	int	g;
	int	b;

	if (!str)
		return (1);
	if (parse_number(&str, &r))
		return (1);
	str = skip_spaces(str);
	if (*str != ',')
		return (1);
	str++;
	if (parse_number(&str, &g))
		return (1);
	str = skip_spaces(str);
	if (*str != ',')
		return (1);
	str++;
	if (parse_number(&str, &b))
		return (1);
	str = skip_spaces(str);
	if (*str != '\0' && *str != '\n')
		return (1);
	return (0);
}

int	check_colors(t_elements *elem)
{
	if (!elem)
		return (1);
	if (!elem->f)
	{
		ft_putendl_fd("Error\nMissing F (floor) color definition", 2);
		return (1);
	}
	if (!elem->c)
	{
		ft_putendl_fd("Error\nMissing C (ceiling) color definition", 2);
		return (1);
	}
	if (validate_rgb_string(elem->f))
	{
		ft_putendl_fd("Error\nInvalid F (must be R,G,B with values 0-255)", 2);
		return (1);
	}
	if (validate_rgb_string(elem->c))
	{
		ft_putendl_fd("Error\nInvalid C (must be R,G,B with values 0-255)", 2);
		return (1);
	}
	return (0);
}
