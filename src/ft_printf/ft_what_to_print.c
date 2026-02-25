/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:33:47 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/06 10:34:03 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_to_print(const char src, va_list arg)
{
	int	re;

	re = 0;
	if (src == 'c')
		re = ft_putchar(va_arg(arg, int));
	else if (src == 's')
		re = ft_putstr(va_arg(arg, char *));
	else if (src == 'p')
		re = (ft_hexa_void(va_arg(arg, void *)));
	else if (src == 'i' || src == 'd')
		re = ft_putnbr(va_arg(arg, int));
	else if (src == 'u')
		re = ft_putnbr_ng(va_arg(arg, unsigned int));
	else if (src == 'x')
		re = ft_hexa_low(va_arg(arg, unsigned int));
	else if (src == 'X')
		re = ft_hexa_upp(va_arg(arg, unsigned int));
	else if (src == '%')
		re += write(1, "%", 1);
	return (re);
}
