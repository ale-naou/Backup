/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:00:45 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:40 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_ptr(t_e *e, t_a *arg, int *i)
{
	*i = print_mem(va_arg(e->ap, void *), arg);
}
