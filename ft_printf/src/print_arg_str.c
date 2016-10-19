/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:00:55 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:44 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_str(t_e *e, t_a *arg, int *i)
{
	while (arg->prec.pt && arg->prec.prec == 0 && arg->width > 0)
	{
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
		arg->width--;
		e->plen++;
	}
	if (arg->mod.l || arg->type == 'S')
		*i = print_str_wchar_t(va_arg(e->ap, wchar_t *), arg);
	else
		*i = print_str(va_arg(e->ap, char *), arg);
}
