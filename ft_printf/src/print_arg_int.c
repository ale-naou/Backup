/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:00:24 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:34 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long int	int_mod(t_e *e, t_a *arg)
{
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.hh)
		return ((char)va_arg(e->ap, int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.h)
		return ((short)va_arg(e->ap, int));
	if (arg->type == 'D' || ((arg->type == 'd' || arg->type == 'i')
				&& arg->mod.l))
		return (va_arg(e->ap, long int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.ll)
		return (va_arg(e->ap, long long int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.j)
		return (va_arg(e->ap, intmax_t));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, int));
}

static int				print_spaces(t_a *arg)
{
	int	len;

	len = 0;
	while (arg->width-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

void					print_arg_int(t_e *e, t_a *arg, int *i)
{
	long long int	va;

	va = int_mod(e, arg);
	if (va == 0 && arg->prec.pt && arg->prec.prec == 0)
	{
		*i += print_spaces(arg);
		return ;
	}
	*i = print_int(va, arg);
	while (arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		write(1, " ", 1);
		(*i)++;
	}
}
