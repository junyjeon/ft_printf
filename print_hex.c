/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 06:19:47 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/13 19:33:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned int hex, int h_len)
{
	unsigned int	hex_p;

	if ()
		unsigned int hex_p;
	if (hex == 0)
		return (++h_len);
	while (hex)
	{
		hex /= 16;
		h_len++;
	}
	return (h_len);
}

static void	put_p(unsigned long long hex)
{
	if (hex > 15)
		put_p(hex / 16);
	write(1, &"0123456789abcdef"[hex % 16], 1);
}

static void	put_Xx(char arg, unsigned int hex)
{
	if (hex > 15)
		put_Xx(arg, hex / 16);
	if (arg == 'x')
		write(1, &"0123456789abcdef"[hex % 16], 1);
	else if (arg == 'X')
		write(1, &"0123456789ABCDEF"[hex % 16], 1);
}

int	print_hex(char arg, va_list ap)
{
	unsigned long long	hex;

	hex = (unsigned long long)va_arg(ap, void *);
	if (arg == 'X' || arg == 'x')
	{
		put_Xx(arg, hex);
		return (hexlen(hex, 0));
	}
	else
	{
		write(1, "0x", 2);
		put_p(hex);
		return (hexlen(hex, 2));
	}
}
