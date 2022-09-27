/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:17:43 by junyojeo          #+#    #+#             */
/*   Updated: 2022/09/23 22:58:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

long long	ft_putnbr(long long n, char *target)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, target, i);
	if (n >= 0)
	{
		write(1, &"0123456789"[n % 10], 1);
		write(1, target)
	}
}

void	div_(long long div, long long ans, char *target)
{
	if (ans )
		div_(div * 10, ans);
	if (ans = target)
	{
		cout << put
	}
		div_()
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long A, B, div, ans;
	char target[4] = "''+-*";
	cin >> A >> B;
	for (int i = 0; i < ans; i++)
	{
		div *= 10;

	}
		cout << 1;
	return (0);
}
