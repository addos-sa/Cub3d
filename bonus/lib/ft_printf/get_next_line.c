/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:01:25 by addos-sa          #+#    #+#             */
/*   Updated: 2025/08/04 12:18:19 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extrafin(char **line, char **extra)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	while ((*line)[i + j] != '\0')
		j++;
	temp = malloc(i + 2);
	if (!temp)
		return ;
	if (j > 0)
		*extra = malloc(j + 2);
	if (!*extra)
		return (free(temp));
	ft_memcp(temp, *line, i + 1);
	ft_memcp(*extra, *line + (i + 1), j);
	free (*line);
	*line = malloc (i + 2);
	if (!*line)
		return (free(temp));
	ft_memcp(*line, temp, i + 1);
	free (temp);
}

void	extraent(char **line, char **extra)
{
	int	i;

	i = 0;
	if (!extra || !*extra)
		return ;
	while ((*extra)[i] != '\0')
		i++;
	*line = malloc (i + 2);
	if (!*line)
		return ;
	ft_memcp(*line, *extra, i + 1);
	free (*extra);
	*extra = NULL;
}

char	*get__line(int fd, char *buffer, char **extra)
{
	char		*line;
	int			tam;

	tam = 1;
	line = NULL;
	if (*extra != NULL)
		extraent(&line, extra);
	while (tam > 0 && stelen_n(line) == 0)
	{
		tam = read(fd, buffer, BUFFER_SIZE);
		if (tam > 0)
			line = ft_strjoi(&line, buffer, tam);
	}
	if (BUFFER_SIZE > 1 && line != NULL)
		extrafin (&line, extra);
	if (tam <= 0 && line != NULL)
	{
		free (*extra);
		if (!line[0])
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*returned;
	static char	*extra;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (extra)
		{
			free (extra);
			extra = NULL;
		}
		return (NULL);
	}
	returned = get__line(fd, buffer, &extra);
	free (buffer);
	return (returned);
}
