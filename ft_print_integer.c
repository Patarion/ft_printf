/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:44:37 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/08 12:25:19 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(int nb, char flag)
{
	long	n;
	char	c;
	int		size;

	n = (long) nb;
	size = 0;
	if (nb >= 0 && flag == '+')
			size += write(1, "+", 1);
	if (nb >= 0 && flag == 0x20)
		size += write(1, " ", 1);
	else if (n < 0)
	{
		size += write(1, "-", 1);
		n = n * -1;
	}
	flag = 0;
	if ((n / 10) > 0)
		size += ft_print_integer((n / 10), flag);
	c = (n % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
