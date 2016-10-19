/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:01:06 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:48 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	unsigned_mod(t_e *e, t_a *arg)
{
	if (arg->type == 'u' && arg->mod.hh)
		return ((unsigned char)va_arg(e->ap, unsigned int));
	if (arg->type == 'u' && arg->mod.h)
		return ((unsigned short)va_arg(e->ap, unsigned int));
	if (arg->type == 'U' || (arg->type == 'u' && arg->mod.l))
		return (va_arg(e->ap, unsigned long int));
	if (arg->type == 'u' && arg->mod.ll)
		return (va_arg(e->ap, unsigned long long int));
	if (arg->type == 'u' && arg->mod.j)
		return (va_arg(e->ap, uintmax_t));
	if (arg->type == 'u' && arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, unsigned int));
}

void						print_arg_unsigned(t_e *e, t_a *arg, int *i)
{
	unsigned long long	va;

	if (arg->prec.pt && arg->prec.prec == 0)
		return ;
	va = unsigned_mod(e, arg);
	*i = print_unsigned_int(va, arg);
	while (arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		write(1, " ", 1);
		(*i)++;
	}
}
