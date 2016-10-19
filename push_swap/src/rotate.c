/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:43:47 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 19:10:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_env *e)
{
	t_struct	*tmp;

	if (e->a_start != NULL && e->a_end != NULL)
	{
		tmp = e->a_start;
		e->a_start = e->a_start->next;
		tmp->next = NULL;
		e->a_end->next = tmp;
		e->a_end = e->a_end->next;
		add_move(e, "ra");
		if (e->stack_display == 1)
			print_stack(e);
	}
}

void	rotate_b(t_env *e)
{
	t_struct	*tmp;

	if (e->b_start != NULL && e->b_end != NULL)
	{
		tmp = e->b_start;
		e->b_start = e->b_start->next;
		tmp->next = NULL;
		e->b_end->next = tmp;
		e->b_end = e->b_end->next;
		add_move(e, "rb");
		if (e->stack_display == 1)
			print_stack(e);
	}
}

void	rotate_both(t_env *e)
{
	t_struct	*tmp;

	if ((e->a_start != NULL && e->a_end != NULL) ||
			(e->b_start != NULL && e->b_end != NULL))
	{
		tmp = e->a_start;
		e->a_start = e->a_start->next;
		tmp->next = NULL;
		e->a_end->next = tmp;
		e->a_end = e->a_end->next;
		tmp = e->b_start;
		e->b_start = e->b_start->next;
		tmp->next = NULL;
		e->b_end->next = tmp;
		e->b_end = e->b_end->next;
		add_move(e, "rr");
		if (e->stack_display == 1)
			print_stack(e);
	}
}
