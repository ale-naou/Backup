/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:47:48 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:12:51 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_mod(t_a *arg)
{
	if (arg->mod.h == 1 && (arg->type == 'c' || arg->type == 'C' ||
		arg->type == 's' || arg->type == 'S' || arg->type == 'p'))
		return (-1);
	if (arg->mod.hh == 1 && (arg->type == 'c' ||
		arg->type == 's' || arg->type == 'p'))
		return (-1);
	if (arg->mod.l == 1 && (arg->type == 'C' || arg->type == 'S'))
		return (-1);
	if (arg->mod.ll == 1 && (arg->type == 'c' || arg->type == 'C' ||
		arg->type == 's' || arg->type == 'S' || arg->type == 'p'))
		return (-1);
	if (arg->mod.j == 1 && (arg->type == 'c' || arg->type == 'C' ||
		arg->type == 's' || arg->type == 'S' || arg->type == 'p'))
		return (-1);
	if (arg->mod.z == 1 && (arg->type == 'c' || arg->type == 'C' ||
		arg->type == 's' || arg->type == 'S' || arg->type == 'p'))
		return (-1);
	return (0);
}

int			check_err(t_a *arg)
{
	if (check_zero(arg) == -1)
		return (-1);
	if (check_space(arg) == -1)
		return (-1);
	if (check_plus(arg) == -1)
		return (-1);
	if (check_diez(arg) == -1)
		return (-1);
	if (check_mod(arg) == -1)
		return (-1);
	return (0);
}
