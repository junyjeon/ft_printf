/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:51:29 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/23 17:29:10 by junyojeo         ###   ########.fr       */
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

void	ft_i(int args, va_list ap, int ans)
{
	if (ans < 0)
	{
		write(1, "-", 1);
		ans *= -1;
	}
	while (args)
	{
		args /= 10;
		write(1, &"0123456789"[args % 10], 1);
	}
}

void	ft_d(int args, va_list ap, int ans)
{
	while (ans)
	{
		write(1, &"0123456789"[ans % 10], 1);
		ans /= 10;
	}
}

void	ft_p(int args, va_list ap, char *ans)
{
	int		ans_len;
	int		i;

	ans_len = ft_strlen(ans);
	i = 0;
	
	while (i < ans_len) 
	{
		write(1, &"0123456789abcdef"[ans[i] / 16], 1);
		write(1, &"0123456789abcdef"[ans[i] % 16], 1);
	}
	
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
//ft_printf("%c", a);
	va_start(ap, args);
	int ans = 0;

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
			
			else if (args == 'x')
			
			else if (args == 'X')	
			
			else if (args == '%')
		}
		else
			write(1, &args[i], 1);
		args++;
	}
	va_end(ap);
	return (0);
}
