/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:40:27 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/08 14:40:44 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa_uint(uintptr_t c)
{
	unsigned long		i;

	i = 16;
	if (c >= i)
	{
		ft_hexa_uint(c / i);
		ft_hexa_uint(c % i);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + '0');
		else
			ft_putchar(c - 10 + 'a');
	}
}

int	ft_hexalenvoid(uintptr_t n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_hexa_void(void *s)
{
	uintptr_t	c;

	if (!s)
		return (write (1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		c = (uintptr_t) s;
		ft_hexa_uint(c);
		return (ft_hexalenvoid(c) + 2);
	}
}
