/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/09 22:03:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, args);
	len = 0;
	i = 0;
	while (args[i])
	{
		if (args[i] == '%')
		{
			i++;
			if (!args[i])
				break ;
			else if (args[i] == 'c' || args[i] == 's' || args[i] == '%')
				len += print_str(args[i], ap);
			else if (args[i] == 'd' || args[i] == 'i' || args[i] == 'u')
				len += print_num(args[i], ap);
			else if (args[i] == 'p' || args[i] == 'x' || args[i] == 'X')
				len += print_hex(args[i], ap);
		}
		else
			len += write(1, &args[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("abcde");
// 	printf("abcde");
// 	return (0);
// }
