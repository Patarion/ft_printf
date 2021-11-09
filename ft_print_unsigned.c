/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:09:39 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/08 12:26:52 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	c;
	int		size;

	size = 0;
	if ((n / 10) > 0)
		size += ft_print_unsigned(n / 10);
	c = (n % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}
