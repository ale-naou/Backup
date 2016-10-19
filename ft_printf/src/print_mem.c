/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:05:59 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:15:02 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_mem(void *p, t_a *arg)
{
	int	len;
	int	plen;

	len = 2;
	plen = len + nbr_len_base((long)p, 16);
	arg->width -= plen;
	while (!arg->flag.mn && !arg->flag.zr && --arg->width >= 0 && (len++))
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	write(1, "0x", 2);
	if (!(arg->prec.pt && arg->prec.prec == 0))
		len += print_base(arg, (long)p, 16, 'a');
	while ((arg->flag.mn || arg->flag.zr) && --arg->width >= 0 && (len++))
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	while ((arg->prec.prec - plen + 2) > 0)
	{
		write(1, "0", 1);
		arg->prec.prec--;
		len++;
	}
	return (len);
}
