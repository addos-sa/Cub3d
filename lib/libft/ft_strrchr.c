/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:12 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/22 12:21:20 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		ult;
	char	*copy;

	i = 0;
	copy = (char *)s;
	ult = 0;
	if ((char)c == '\0')
	{
		return ((char *)(s + ft_strlen(s)));
	}
	while (i < ft_strlen(s))
	{
		if (copy[i] == (char)c)
			ult = i;
		i++;
	}
	if (copy[ult] == (char)c)
		return ((char *)(s + ult));
	else
		return (NULL);
}
