/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:09:21 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/07 17:03:26 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_adress(void *str)
{
	int	size;

	size = 0;
	if (!str)
	{
		write(1, "0x0", 3);
		return (3);
	}
	size += write(1, "0x", 2);
	size += ft_print_hex((unsigned long) str);
	return (size);
}
