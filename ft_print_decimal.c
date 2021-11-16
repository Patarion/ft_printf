/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:49:55 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/07 17:03:58 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int nb, char flag)
{
	char	c;
	int		size;
	long	n;

	n = (long) nb;
	size = 0;
	if (nb >= 0 && flag == 32)
		size += write(1, " ", 1);
	if (nb >= 0 && flag == '+')
			size += write(1, "+", 1);
	else if (n < 0)
	{
		size += write(1, "-", 1);
		n = n * -1;
	}
	flag = 0;
	if ((n / 10) > 0)
		size += ft_print_decimal((n / 10), flag);
	c = (n % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
