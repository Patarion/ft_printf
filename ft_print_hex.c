/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:38:33 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/08 12:24:24 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long nb, char flag)
{
	char		c;
	int			size;

	size = 0;
	if (flag == 'x' && nb)
		size += write(1, "0x", 2);
	flag = 0;
	if ((nb / 16) > 0)
		size += ft_print_hex((nb / 16), flag);
	if ((nb % 16) > 9)
	{
		c = (nb % 16) + 'W';
		size += write(1, &c, 1);
	}
	else
	{
		c = (nb % 16) + '0';
		size += write(1, &c, 1);
	}
	return (size);
}
