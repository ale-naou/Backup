/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:00:32 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:37 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_percent(t_e *e, t_a *arg, int *i)
{
	if (arg->prec.pt && arg->width == 0)
	{
		write(1, &arg->type, 1);
		*i += 1;
		return ;
	}
	arg->width--;
	while (!arg->flag.mn && arg->width-- > 0)
	{
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
		e->plen++;
	}
	write(1, &arg->type, 1);
	*i += 1;
	while (arg->flag.mn && arg->width-- > 0)
	{
		write(1, " ", 1);
		e->plen++;
	}
}
