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

static int	nbrlen(int n)
{
	int	len;
	
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	if (n >= 0)
		write(1, &"0123456789"[n % 10], 1);
}

static void	ft_u(unsigned int n)
{
	if (n >= 10)
		ft_u(n / 10);
	if (n >= 0)
		write(1, &"0123456789"[n % 10], 1);
}

int	print_num(char args, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (args == 'd' || args == 'i')
	{
		ft_putnbr(n);
		return (nbrlen(n));
	}
	else if (args == 'u')
	{
		ft_u((unsigned int)n);
		return (nbrlen(n));
	}
	return (0);
}
