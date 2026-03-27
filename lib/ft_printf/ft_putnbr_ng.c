/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:16:52 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/08 18:17:13 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	creation(char *num, unsigned int nb)
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

int	ft_putnbr_ng(unsigned int n)
{
	char	num[11];
	int		re;

	re = creation(num, n);
	if (n == 0)
		re += write(1, "0", 1);
	return (re);
}
