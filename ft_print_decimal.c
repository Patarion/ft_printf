/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:49:55 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/23 08:52:48 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int nb, char flag)
{
	char	c;
	int		size;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	size = 0;
	if (nb >= 0 && flag == 32)
		size += write(1, " ", 1);
	if (nb >= 0 && flag == '+')
			size += write(1, "+", 1);
	else if (nb < 0)
	{
		size += write(1, "-", 1);
		nb = nb * -1;
	}
	flag = 0;
	if ((nb / 10) > 0)
		size += ft_print_decimal((nb / 10), flag);
	c = (nb % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
