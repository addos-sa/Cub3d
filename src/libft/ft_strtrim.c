/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:25:51 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/28 12:26:20 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comprobation(const char *s1, char const *set, size_t i)
{
	int	c;
	int	bit;

	bit = 0;
	c = 0;
	while (set[c] != '\0')
	{
		if (s1[i] == set[c])
			bit = 1;
		c++;
	}
	return (bit);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	pos;
	size_t	tms;
	char	*trim;

	i = 0;
	pos = 0;
	tms = 0;
	while (comprobation(s1, set, i) == 1 && s1[i] != '\0')
		i++;
	while (comprobation(s1, set, ft_strlen(s1) - tms - 1) == 1
		&& i < ft_strlen(s1))
		tms++;
	trim = malloc((ft_strlen(s1 + i) - tms) + 1);
	if (trim == NULL)
		return (NULL);
	while (s1[i + tms] != '\0')
	{
		trim[pos] = s1[i];
		i++;
		pos++;
	}
	trim[pos] = '\0';
	return (trim);
}
