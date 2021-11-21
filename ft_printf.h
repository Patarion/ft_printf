/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:52:59 by jgagnon           #+#    #+#             */
/*   Updated: 2021/11/21 11:56:04 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_search
{
	int		j;
	char	f;
}	t_find;

int	ft_print_adress(void *str);
int	ft_print_char(char *str);
int	ft_print_decimal(int nb, char flag);
int	ft_print_hex(unsigned long nb, char flag);
int	ft_print_hx(unsigned int nb, char flag);
int	ft_print_integer(int nb, char flag);
int	ft_print_percent(void);
int	ft_print_str(char *str);
int	ft_print_unsigned(unsigned int nb);
int	ft_printf(const char *format, ...);

#endif
