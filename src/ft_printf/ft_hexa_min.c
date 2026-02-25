/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:52:54 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/12 13:52:59 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_low(unsigned int s)
{
	if (s >= 16)
	{
		ft_hexa_low(s / 16);
		ft_hexa_low(s % 16);
	}
	else
	{
		if (s <= 9)
			ft_putchar(s + '0');
		else
			ft_putchar(s - 10 + 'a');
	}
	return (ft_hexalen(s));
}

int	ft_hexa_upp(unsigned int s)
{
	if (s >= 16)
	{
		ft_hexa_upp(s / 16);
		ft_hexa_upp(s % 16);
	}
	else
	{
		if (s <= 9)
			ft_putchar(s + '0');
		else
			ft_putchar(s - 10 + 'A');
	}
	return (ft_hexalen(s));
}
