/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:50:01 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:13:27 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_flags(const char *format, int i, t_a *arg)
{
	while (is_flag(format[i]))
	{
		format[i] == ' ' ? arg->flag.sp = 1 : 0;
		format[i] == '+' ? arg->flag.pl = 1 : 0;
		format[i] == '-' ? arg->flag.mn = 1 : 0;
		format[i] == '#' ? arg->flag.di = 1 : 0;
		format[i] == '0' ? arg->flag.zr = 1 : 0;
		i++;
	}
	return (i);
}
