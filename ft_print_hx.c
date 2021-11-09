/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:36:43 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/08 12:25:02 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hx(unsigned int nb)
{
	char	c;
	int		size;

	size = 0;
	if ((nb / 16) > 0)
		size += ft_print_hx(nb / 16);
	if ((nb % 16) > 9)
	{
		c = (nb % 16) + '7';
		size += write(1, &c, 1);
	}
	else
	{
		c = (nb % 16) + '0';
		size += write(1, &c, 1);
	}
	return (size);
}
