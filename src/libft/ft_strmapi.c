/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:39:07 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/01 12:39:37 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	i = 0;
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
