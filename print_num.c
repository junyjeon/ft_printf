/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:36:01 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/27 08:18:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_di(int n, int len)
{
	if (n == -2147483648)
		len = write(1, "-2147483648", 11);
	else if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_di(n / 10, len);
	if (n >= 0)
		len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

static int	put_u(unsigned int n, int len)
{
	if (n >= 10)
		put_u(n / 10, len);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	print_num(char args, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (args == 'd' || args == 'i')
		return (put_di(n, 0));
	return (put_u((unsigned int)n, 0));
}
