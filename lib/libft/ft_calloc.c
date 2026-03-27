/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:38:26 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/23 11:38:28 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	s1 = malloc(nmemb * size);
	if (s1 == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
