/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:13 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 12:22:19 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	find;

	i = 0;
	copy = (unsigned char *)s;
	find = (unsigned char )c;
	if (n == '\0')
		return (NULL);
	while (copy[i] != find && i < n - 1)
		i++;
	if (copy[i] == find)
		return ((unsigned char *)copy + i);
	else
		return (NULL);
}
