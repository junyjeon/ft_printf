/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/18 21:18:46 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	arg(char arg, va_list ap, int out, int *len)
{
	if (arg == 'c' || arg == 's' || arg == '%')
	{
		if (!print_str(arg, ap, &out))
			return (false);
	}
	else if (arg == 'd' || arg == 'i' || arg == 'u')
	{
		if (!print_num(arg, ap, &out))
			return (false);
	}
	else if (arg == 'p' || arg == 'x' || arg == 'X')
	{
		if (!print_hex(arg, ap, &out))
			return (false);
	}
	*len += out;
	return (true);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(ap, args);
	while (args[++i])
	{
		if (args[i++] == '%')
		{
			if (!arg(args[i], ap, 0, &len))
				return (-1);
		}
		else
		{
			if (!write(1, &args[--i], 1))
				return (-1);
			len += 1;
		}
	}
	va_end(ap);
	return (len);
}
