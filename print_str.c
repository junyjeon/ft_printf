/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:31:14 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/06 20:22:48 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_c(char c)
{
	return (write(1, &c, 1));
}

static int	ft_s(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (write(1, str, i));
}

int	print_str(char args, va_list ap)
{
	if (args == 's')
		return (ft_s(va_arg(ap, char *)));
	else if (args == 'c')
		return (ft_c(va_arg(ap, int)));
	else if (args == '%')
		return (ft_c('%'));
	return (0);
}
