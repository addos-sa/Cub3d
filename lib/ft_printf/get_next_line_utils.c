/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:06:44 by addos-sa          #+#    #+#             */
/*   Updated: 2025/08/04 12:18:33 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strle(const char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	return (i);
}

int	stelen_n(char *line)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		bit = 1;
	return (bit);
}

void	ft_memcp(char *dest, char *src, size_t n)
{
	size_t			i;

	i = 0;
	if (dest == NULL || src == NULL)
		return ;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoi(char **s1, char *s2, int tam)
{
	char	*join;

	join = malloc(ft_strle(*s1) + tam + 1);
	if (join == NULL)
		return (NULL);
	if (*s1)
		ft_memcp(join, *s1, ft_strle(*s1));
	ft_memcp(join + ft_strle(*s1), s2, tam);
	join[ft_strle(*s1) + tam] = '\0';
	free (*s1);
	*s1 = NULL;
	return (join);
}
