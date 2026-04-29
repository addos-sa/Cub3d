/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:09:00 by addos-sa          #+#    #+#             */
/*   Updated: 2025/02/10 13:36:58 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	tamd;
	unsigned int	tams;
	unsigned int	i;

	tamd = ft_strlen(dst);
	tams = ft_strlen((char *)src);
	i = 0;
	if (size <= tamd)
		return (tams + size);
	while (src[i] != '\0' && (tamd + i) < (size - 1))
	{
		dst[tamd + i] = src[i];
		i++;
	}
	dst[tamd + i] = '\0';
	return (tamd + tams);
}
