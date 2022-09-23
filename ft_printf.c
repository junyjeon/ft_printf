/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/23 19:19:12 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

//args에 +가 있으면? 아님 reverstrim처럼 사이에 있으면? strchr로 찾아서 아래 함수 수행 후 다음 반복문 들어가기.
int	sum(int num_args, ...)
{
	int		arg;
	int		res;
	int		i;
	va_list	ap;//가변인수의 포인터

	arg = 0;
	res = 0;
	va_start(ap, num_args);
	i = 0;
	while (i < num_args)
	{
		arg = va_arg(ap, int);
		res += arg;
		i++;
	}
	return (res);
}

void	ft_putnbf(int n)
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

void	ft_X(int args, va_list ap, int n)
{
	if (n > 15)
		ft_X(args, ap, n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

void	ft_x(int args, va_list ap, int n)
{
	if (n > 15)
		ft_x(args, ap, n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_u(int args, va_list ap, unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	if (n >= 0)
		write(1, &"0123456789"[n % 10], 1);
}

void	ft_i(int args, va_list ap, int n)
{
	ft_putnbf(n);
}

void	ft_d(int args, va_list ap, int n)
{
	ft_putnbf(n);
}

void	ft_p(int args, va_list ap, unsigned long long n)
{
	if (n > 15)
		ft_p(args, ap, n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_s(int args, va_list ap, char *ans)
{
	write(1, ans, ft_strlen(ans));
}

void	ft_c(int args, va_list ap, char ans)
{
	write(1, &ans, 1);
}

char	*ft_printf(char *args, ...)
{
	va_list	ap;

	va_start(ap, args);
	while (*args)
	{
		if (*args == '%')
		{
			args++;
			if (!(*args))
				break ;
			//문자열, 정수, x로 나누기
			if (args == 'c')
				ft_c(args, ap, va_arg(ap, int));
			else if (args == 's')
				ft_s(args, ap, va_arg(ap, char *));
			else if (args == 'p')
				ft_p(args, ap, va_arg(ap, void *));
			else if (args == 'd')
				ft_d(args, ap, va_arg(ap, int));
			else if (args == 'i')
				ft_i(args, ap, va_arg(ap, int))
			else if (args == 'u')
				ft_u(args, ap, va_arg(ap, unsigned int));
			else if (args == 'x')
				ft_x(args, ap, va_arg(ap, unsigned int));
			else if (args == 'X')	
				ft_X(args, ap, va_arg(ap, unsigned int));
			else if (args == '%')
				write(1, "%", 1);
		}
		else
			write(1, &args, 1);
		args++;
	}
	va_end(ap);
	return (0);
}
