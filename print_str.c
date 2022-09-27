/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:31:14 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/27 08:45:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{	
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

static int	ft_s(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

static int	ft_c(char c)
{
	write(1, &c, 1);
	return (0);
}

int	print_str(char args, va_list ap)
{
	if (args == 'c')
		return (ft_c(va_arg(ap, int)));
	else if (args == 's')
		return (ft_s(va_arg(ap, char *)));
	else if (args == '%')
		return (ft_c('%'));
	return (0);
}
