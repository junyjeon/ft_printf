/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:00:00 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/18 20:22:04 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

bool	print_str(char arg, va_list ap, int *out);
bool	print_num(char arg, va_list ap, int *out);
bool	print_hex(char arg, va_list ap, int *out);
int		ft_printf(const char *args, ...);

#endif
