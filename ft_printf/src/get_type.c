/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:52:45 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:13:52 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_type(const char *format, int i, t_a *arg)
{
	arg->type = format[i];
	if (is_type(format[i]))
		return (i + 1);
	return (i);
}
