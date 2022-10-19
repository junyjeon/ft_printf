/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:36:01 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/18 21:19:07 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(long n)
{
	int	n_len;

	n_len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		n_len++;
	}
	while (n > 0)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

static bool	put_di(int n)
{
	if (n == -2147483648)
	{
		if (!write(1, "-2147483648", 11))
			return (false);
		return (true);
	}
	else if (n < 0)
	{
		if (!write(1, "-", 1))
			return (false);
		n *= -1;
	}
	if (n > 9)
		put_di(n / 10);
	if (!write(1, &"0123456789"[n % 10], 1))
		return (false);
	return (true);
}

static bool	put_u(unsigned int n)
{
	if (n > 9)
		put_u(n / 10);
	if (!write(1, &"0123456789"[n % 10], 1))
		return (false);
	return (true);
}

bool	print_num(char arg, va_list ap, int *out)
{
	int	n;

	n = va_arg(ap, int);
	if (arg == 'd' || arg == 'i')
	{
		if (!put_di(n))
			return (false);
		*out = nbrlen(n);
	}
	else
	{
		if (!put_u(n))
			return (false);
		*out = nbrlen((unsigned int)n);
	}
	return (true);
}
