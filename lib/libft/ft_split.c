/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:51:16 by addos-sa          #+#    #+#             */
/*   Updated: 2025/07/25 12:48:39 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	countw;

	i = 0;
	word = 0;
	countw = 0;
	while (s[i] != '\0')
	{
		if (word == 0 && s[i] != c)
		{
			countw++;
			word = 1;
		}
		else if (word == 1 && s[i] == c)
			word = 0;
		i++;
	}
	return (countw);
}

static int	count_lett(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		pos;
	char	**split;

	i = 0;
	pos = 0;
	split = ft_calloc((count_words(s, c) + 1) * sizeof(char *), sizeof(char));
	if (split == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			split[pos] = ft_calloc(count_lett(s + i, c) + 1, sizeof(char));
			if (split[pos] == NULL)
				return (free_split(split));
			ft_memcpy(split[pos], s + i, count_lett(s + i, c));
			pos++;
		}
		i = i + count_lett(s + i, c) + 1;
		if (i > ft_strlen(s))
			return (split);
	}
	return (split);
}
