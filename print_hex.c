/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 06:19:47 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/27 08:06:19 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_Xx(char format, unsigned int n, int len)
{
	if (n > 15)
		put_Xx(format, n / 16, len);
	if (format == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (format == 'X')
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

static int	put_p(unsigned long long n, int len)
{
	if (n > 15)
		put_p(n / 16, len);
	len += write(1, &"0123456789abcdef"[n % 16], 1);
	return (len);
}

int	print_hex(char format, va_list ap)
{
	if (format == 'X' || format == 'x')
		return (put_Xx(format, (unsigned long long)va_arg(ap, int), 0));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		return (put_p((unsigned long long)va_arg(ap, void *), 2));
	}
	return (0);
}
