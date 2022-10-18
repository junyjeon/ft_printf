/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/18 17:08:02 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define	str	(args[i] == 'c' || args[i] == 's' || args[i] == '%')
#define num (args[i] == 'd' || args[i] == 'i' || args[i] == 'u')
#define hex (args[i] == 'p' || args[i] == 'x' || args[i] == 'X')

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		*out;

	i = -1;
	len = 0;
	out = 0;
	va_start(ap, args);
	while (args[++i])
	{
		*out = 0;
		if (args[i++] == '%')
			if (!(str ? print_str(args[i], ap, out) : (num ? print_num(args[i], ap, out) : (hex ? print_hex(args[i], ap, out) : (write(1, &args[--i], 1) ? *out = 1 : false)))))
				return (-1);
		len += *out;
	}
	va_end(ap);
	return (len);
}


			// if (args[i] == 'c' || args[i] == 's' || args[i] == '%')
			// {
			// 	if (!print_str(args[i], ap, out))
			// 		return (-1);
			// 	len += *out;
			// }
			// else if (args[i] == 'd' || args[i] == 'i' || args[i] == 'u')
			// {
			// 	if (!print_num(args[i], ap, out))
			// 		return (-1);
			// 	len += *out;
			// }
			// else if (args[i] == 'p' || args[i] == 'x' || args[i] == 'X')
			// {
			// 	if (!print_hex(args[i], ap, out))
			// 		return (-1);
			// 	len += *out;
			// }
			// else
			// 	return (-1);
