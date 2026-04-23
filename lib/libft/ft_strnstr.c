/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:14 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 13:39:47 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comprobation(const char *to_find, const char *str, int i)
{
	int		bite;
	size_t	c;

	c = 0;
	bite = 0;
	while (str[i] == to_find[c] && to_find[c] != '\0')
	{
		c++;
		i++;
	}
	if (ft_strlen(to_find) == c)
		bite = 1;
	return (bite);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		bit;

	bit = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && bit == 0 && i < len)
	{
		if (big[i] == little[0])
		{
			if (comprobation(little, big, i) == 1)
				bit = 1;
		}
		i++;
	}
	i--;
	if (bit == 1 && (ft_strlen(little) + i) <= len)
		return ((char *)big + i);
	else
	{
		return (NULL);
	}
}
