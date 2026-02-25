/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:21:01 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/25 11:21:51 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	bit;
	int	total;

	i = 0;
	bit = 1;
	total = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r')
		|| nptr[i] == ' ')
		i++;
	if (!nptr)
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			bit = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = total * 10 + (nptr[i] - 48);
		i++;
	}
	return (total * bit);
}
