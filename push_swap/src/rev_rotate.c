/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:44:27 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 19:30:23 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_a(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	if (e->a_start != NULL && e->a_end != NULL)
	{
		tmp = e->a_end;
		tmp2 = e->a_start;
		while (tmp2->next != e->a_end)
			tmp2 = tmp2->next;
		e->a_end = tmp2;
		e->a_end->next = NULL;
		tmp->next = e->a_start;
		e->a_start = e->a_start->next;
		e->a_start = tmp;
		add_move(e, "rra");
		if (e->stack_display == 1)
			print_stack(e);
	}
}

void		rev_rotate_b(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	if (e->b_start != NULL && e->b_end != NULL)
	{
		tmp = e->b_end;
		tmp2 = e->b_start;
		while (tmp2->next != e->b_end)
			tmp2 = tmp2->next;
		e->b_end = tmp2;
		e->b_end->next = NULL;
		tmp->next = e->b_start;
		e->b_start = e->b_start->next;
		e->b_start = tmp;
		add_move(e, "rrb");
		if (e->stack_display == 1)
			print_stack(e);
	}
}

static void	rev_rotate_both_a(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	tmp = e->a_end;
	tmp2 = e->a_start;
	while (tmp2->next != e->a_end)
		tmp2 = tmp2->next;
	e->a_end = tmp2;
	e->a_end->next = NULL;
	tmp->next = e->a_start;
	e->a_start = e->a_start->next;
	e->a_start = tmp;
}

static void	rev_rotate_both_b(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	tmp = e->b_end;
	tmp2 = e->b_start;
	while (tmp2->next != e->b_end)
		tmp2 = tmp2->next;
	e->b_end = tmp2;
	e->b_end->next = NULL;
	tmp->next = e->b_start;
	e->b_start = e->b_start->next;
	e->b_start = tmp;
}

void		rev_rotate_both(t_env *e)
{
	if ((e->a_start != NULL && e->a_end != NULL) ||
			(e->b_start != NULL && e->b_end))
	{
		rev_rotate_both_a(e);
		rev_rotate_both_b(e);
		add_move(e, "rrr");
		if (e->stack_display == 1)
			print_stack(e);
	}
}
