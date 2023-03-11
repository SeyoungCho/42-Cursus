/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:34:18 by seycho            #+#    #+#             */
/*   Updated: 2023/03/11 22:17:15 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion(const char **format, va_list args)
{
	int	printed_len;

	printed_len = 0;
	if (**format == 's')
		printed_len += ft_putstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		printed_len += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		printed_len += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		printed_len += ft_puthex(va_arg(args, unsigned int), **format);
	else if (**format == 'c')
		printed_len += ft_putchar(va_arg(args, int));
	else if (**format == 'p')
	{
		printed_len += ft_putstr("0x");
		printed_len += ft_puthex((unsigned long long)va_arg(args, void *), 'x');
	}
	else if (**format == '%')
		printed_len += ft_putchar('%');
	(*format)++;
	return (printed_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_len;

	printed_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_len += print_conversion(&format, args);
		}
		else
			printed_len += write(1, format++, 1);
	}
	va_end(args);
	return (printed_len);
}
