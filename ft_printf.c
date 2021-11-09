/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:27:43 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/08 12:22:40 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(const char *format, va_list argp)
{
	int	word;

	word = 0;
	if (*++format == 'p')
		word += ft_print_adress(va_arg(argp, void *));
	else if (*format == 'c')
		word += ft_print_char(va_arg(argp, char *));
	else if (*format == 'd')
		word += ft_print_decimal(va_arg(argp, long));
	else if (*format == 'x')
		word += ft_print_hex(va_arg(argp, unsigned int));
	else if (*format == 'X')
		word += ft_print_hx(va_arg(argp, unsigned int));
	else if (*format == 'i')
		word += ft_print_integer(va_arg(argp, int));
	else if (*format == '%')
		word += ft_print_percent();
	else if (*format == 's')
		word += ft_print_str(va_arg(argp, char *));
	else if (*format == 'u')
		word += ft_print_unsigned(va_arg(argp, unsigned long));
	else
		return (0);
	return (word);
}

int	ft_printf(const char *format, ...)
{
	va_list		argp;
	int			size;

	va_start (argp, format);
	size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			size += ft_print_arg(format++, argp);
		}
		else
			size += write(1, format, 1);
		format++;
	}
	va_end(argp);
	return (size);
}
