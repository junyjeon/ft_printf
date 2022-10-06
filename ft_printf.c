/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/27 09:06:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				len += print_str(format[i], ap);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				len += print_num(format[i], ap);
			else if (format[i] == 'p' || format[i] == 'x' || format[i] == 'X')
				len += print_hex(format[i], ap);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

// int main(void)
// {
// 	ft_printf("%%");
// 	return (0);
// }
