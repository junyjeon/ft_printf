/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:31:14 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/18 17:07:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_c(char c, int *out)
{
	if (!write(1, &c, 1))
		return (false);
	*out = 1;
	return (true);
}

static bool	ft_s(char *str, int *out)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	if (!write(1, str, i))
		return (false);
	*out = i;
	return (true);
}

bool	print_str(char arg, va_list ap, int *out)
{
	if (arg == 's')
		return (ft_s(va_arg(ap, char *), out));
	else if (arg == 'c')
		return (ft_c(va_arg(ap, int), out));
	else
		return (ft_c('%', out));
}
