/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:27:15 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 18:14:11 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		b_sort(t_env *e)
{
	t_struct	*tmp;

	tmp = e->b_start;
	if (tmp == NULL || tmp->next == NULL)
		return (2);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (2);
}

int		a_sort(t_env *e)
{
	t_struct	*tmp;

	tmp = e->a_start;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_sort(t_env *e)
{
	int		i;

	i = 0;
	i += a_sort(e);
	i += b_sort(e);
	return (i);
}
