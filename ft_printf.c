/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/13 19:16:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (args[i] == 'c' || args[i] == 's' || args[i] == '%')
				len += print_str(args[i], ap);
			else if (args[i] == 'd' || args[i] == 'i' || args[i] == 'u')
				len += print_num(args[i], ap);
			else if (args[i] == 'p' || args[i] == 'x' || args[i] == 'X')
				len += print_hex(args[i], ap);
			else
				return (-1);
		}
		else
			len += write(1, &args[--i], 1);
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	int i = 0;
// 	int *p = 17;
	
// 	i = ft_printf("|%d|\n", -2147483640);
// 	printf("%d\n", i);
// 	printf("%p\n", p);
// 	printf("%x\n", 17);
// 	return (0);
// }
