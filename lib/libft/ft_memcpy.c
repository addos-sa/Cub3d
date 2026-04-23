/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:28:45 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 10:37:33 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*o;

	i = 0;
	o = (unsigned char *)src;
	t = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		t[i] = o[i];
		i++;
	}
	dest = (void *)t;
	return (dest);
}
