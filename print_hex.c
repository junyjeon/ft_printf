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

static int	hexlen(char args, unsigned long long n)
{
	int	len;

	if (args == 'p')
		len = 2;
	else
		len = 0;
	if (n == 0)
		return (++len);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_X(int args, int n)
{
	if (n > 15)
		ft_X(args, n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

static void	ft_x(int args, int n)
{
	if (n > 15)
		ft_x(args, n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

static void	ft_p(int args, unsigned long long n)
{
	if (n > 15)
		ft_p(args, n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	print_hex(char args, va_list ap)
{
	unsigned long long	hex;

	hex = (unsigned long long)va_arg(ap, void *);
	if (!hex)
		return (0);
	if (args == 'p')
	{
		write(1, "0x", 2);
		ft_p(args, hex);
	}
	else if (args == 'x')
		ft_x(args, hex);
	else if (args == 'X')
		ft_X(args, hex);
	return (hexlen(args, hex));
}
