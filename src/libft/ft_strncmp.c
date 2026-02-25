/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:52 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 12:21:56 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				total;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	total = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (total == 0 && (cs1[i] != '\0' || cs2[i] != '\0') && i < n)
	{
		if (cs1[i] != cs2[i])
			total = cs1[i] - cs2[i];
		i++;
	}
	return (total);
}
