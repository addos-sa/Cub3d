/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:54:36 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/01 13:55:03 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	creation(char *num, int nb, int fd)
{
	int	c;

	c = 0;
	while (nb != 0)
	{
		num[c] = (nb % 10) + '0';
		nb /= 10;
		c++;
	}
	c--;
	while (c >= 0)
	{
		write(fd, &num[c], 1);
		c--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		creation(num, n, fd);
		if (n == 0)
			write(fd, "0", 1);
	}
}
