/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:36:09 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 10:57:05 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*copd;
	const unsigned char	*cops;
	size_t				i;

	i = n;
	cops = (const unsigned char *)src;
	copd = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (cops < copd)
	{
		while (i > 0)
		{
			i--;
			copd[i] = cops[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
