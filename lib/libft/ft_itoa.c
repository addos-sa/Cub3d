/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:47:11 by addos-sa          #+#    #+#             */
/*   Updated: 2025/04/30 12:47:19 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting(long n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		c++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*full;
	long	nb;

	nb = n;
	i = counting(nb);
	full = ft_calloc((i + 1), sizeof(char));
	if (full == NULL)
		return (NULL);
	full[0] = 48;
	if (nb == 0)
		return (full);
	if (nb < 0)
	{
		full[0] = '-';
		nb = nb * -1;
	}
	while (i-- > 0)
	{
		if (full[i] != '-')
			full[i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (full);
}
