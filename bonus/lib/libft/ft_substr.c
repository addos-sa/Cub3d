/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:37:08 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/28 08:37:28 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*smaller;

	if (start > ft_strlen(s))
	{
		smaller = (char *)malloc((1) * sizeof(char));
		if (smaller == NULL)
			return (NULL);
		smaller[0] = '\0';
		return (smaller);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	smaller = (char *)malloc((len + 1) * sizeof(char));
	if (smaller == NULL)
		return (NULL);
	ft_memcpy(smaller, s + start, len);
	smaller[len] = '\0';
	return (smaller);
}
