/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:13:06 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 15:41:24 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"

static int	ft_format(char c, va_list pa)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(pa, int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(pa, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(pa, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(pa, char *));
	else if (c == 'p')
		count += ft_putadd(va_arg(pa, void *));
	else if (c == 'x')
		count += ft_puthexa(va_arg(pa, unsigned int), c);
	else if (c == 'X')
		count += ft_puthexa(va_arg(pa, unsigned int), c);
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (count);
			count += ft_format(s[++i], ap);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
