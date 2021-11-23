/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:27:43 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/21 11:55:48 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg_mandatory(const char *format, va_list argp, t_find flag)
{
	int	word;

	word = 0;
	if (*(++format) == 'p')
		word += ft_print_adress(va_arg(argp, void *));
	else if (*format == 'c')
		word += ft_print_char(va_arg(argp, char *));
	else if (*format == 'd')
		word += ft_print_decimal(va_arg(argp, int), flag.f);
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

int	ft_set(const char *format, char *set)
{
	int	i;

	i = 0;
	while (*format != set[i] && set[i] != '\0')
		i++;
	if (set[i] == '\0')
		return (0);
	else
		return (i);
}

t_find	ft_find_flag(const char *format, t_find flag)
{
	flag.j = 0;
	flag.f = 0;
	if (ft_set(format + 1, "pcdxXi%su") == 0)
		flag.j++;
	while (*(format + flag.j) == 32)
		flag.j++;
	if (*(format + flag.j) == 'i' || *(format + flag.j) == 'd'
		|| *(format + flag.j) == 's')
		flag.f = 32;
	if (*(format + flag.j) == '#' && (*(format + flag.j + 1) == 'x'))
		flag.f = 'x';
	else if (*(format + flag.j) == '#' && (*(format + flag.j + 1) == 'X'))
		flag.f = 'X';
	while (*(format + flag.j + 1) == '+')
		flag.j++;
	if (*(format + flag.j) == '+' && (*(format + flag.j + 1) == 'i'
			|| *(format + flag.j + 1) == 'd'))
		flag.f = '+';
	if (flag.f != 0 && flag.f != 32)
		flag.j++;
	return (flag);
}

int	ft_printf(const char *format, ...)
{
	va_list		argp;
	int			size;
	t_find		flag;

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
				format = format + flag.j - 1;
			size += ft_print_arg_mandatory((format++), argp, flag);
		}
		else
			size += write(1, format, 1);
		format++;
	}
	va_end(argp);
	return (size);
}
