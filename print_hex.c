/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 06:19:47 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/06 20:22:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_Xx(char args, unsigned int n, int len)
{
	if (n > 15)
		put_Xx(args, n / 16, len);
	if (args == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (args == 'X')
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

int	print_hex(char args, va_list ap)
{
	if (args == 'X' || args == 'x')
		return (put_Xx(args, (unsigned long long)va_arg(ap, int), 0));
	else if (args == 'p')
	{
		write(1, "0x", 2);
		return (put_p((unsigned long long)va_arg(ap, void *), 2));
	}
	return (0);
}
