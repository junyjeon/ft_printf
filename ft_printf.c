/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/27 09:02:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			if (format[i] == 'c' || format[i] == 's')
				print_str(format[i], ap);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				print_num(format[i], ap);
			else if (format[i] == 'p' || format[i] == 'x' || format[i] == 'X')
				print_hex(format[i], ap);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
