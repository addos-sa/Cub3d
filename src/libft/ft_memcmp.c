/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:49 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 12:22:51 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				total;
	unsigned char	*cop1;
	unsigned char	*cop2;

	i = 0;
	total = 0;
	cop1 = (unsigned char *)s1;
	cop2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (i < n && total == 0)
	{
		if (cop1[i] != cop2[i])
			total = cop1[i] - cop2[i];
		i++;
	}
	return (total);
}
