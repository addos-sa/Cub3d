/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:04:49 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/06 09:14:36 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *src, ...)
{
	int		countarg;
	va_list	arg;
	int		i;

	va_start(arg, src);
	i = 0;
	countarg = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '%' && src[i + 1] != '\0')
		{
			i++;
			countarg = countarg + what_to_print(src[i], arg);
		}
		else if (src[i] != '%')
			countarg += write (1, &src[i], 1);
		i++;
	}
	va_end(arg);
	return (countarg);
}
