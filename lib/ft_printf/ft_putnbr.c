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

#include "ft_printf.h"

static int	creation(char *num, int nb)
{
	int	c;
	int	g;

	c = 0;
	while (nb != 0)
	{
		num[c] = (nb % 10) + '0';
		nb /= 10;
		c++;
	}
	g = c;
	c--;
	while (c >= 0)
	{
		write(1, &num[c], 1);
		c--;
	}
	return (g);
}

int	ft_putnbr(int n)
{
	char	num[11];
	int		re;

	re = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			re = write(1, "-", 1);
			n = n * -1;
		}
		re = re + creation(num, n);
		if (n == 0)
			re = write(1, "0", 1);
	}
	return (re);
}
