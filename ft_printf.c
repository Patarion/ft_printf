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

int	ft_print_arg_mandatory(const char *format, va_list argp, find flag)
{
	int	word;

	word = 0;
	if (*(++format) == 'p')
		word += ft_print_adress(va_arg(argp, void *));
	else if (*format == 'c')
		word += ft_print_char(va_arg(argp, char *));
  else if (*format == 'd')
    word += ft_print_decimal(va_arg(argp, long), flag.f);
	else if (*format == 'x')
		word += ft_print_hex(va_arg(argp, unsigned int), flag.f);
	else if (*format == 'X')
		word += ft_print_hx(va_arg(argp, unsigned int), flag.f);
	else if (*format == 'i')
		word += ft_print_integer(va_arg(argp, int), flag.f);
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

find	ft_find_flag(const char *format, find flag)
{
	flag.j = 0;
	flag.f = 0;
	format++;
	while(*(format + 1) == 32)
	{
		flag.j++;
		format++;
	}
	if (*(format + 1) == 'i' || *(format + 1) == 'd' || *(format + 1) == 's')
		flag.f = 32;
  if (*format == '#' && (*(format + 1) == 'x'))
    flag.f = 'x';
  else if (*format == '#' && (*(format + 1) == 'X'))
    flag.f = 'X';
  else if (*format == '+' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
    flag.f = '+';
	if (*(format + 1) == '+' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
	{
		flag.f = '+';
		flag.j++;
	}
	flag.j++;
  return (flag);
}

int	ft_printf(const char *format, ...)
{
	va_list		argp;
	int				size;
	find			flag;

	va_start (argp, format);
	size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			flag.f = 0;
			flag.j = 0;
			flag = ft_find_flag(format, flag);
			if (flag.f != 0)
      	format = format + flag.j;
			size += ft_print_arg_mandatory((format++), argp, flag);
		}
		else
			size += write(1, format, 1);
		format++;
	}
	va_end(argp);
	return (size);
}
