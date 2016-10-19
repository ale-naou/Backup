/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:29:58 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/27 18:55:22 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_move(t_env *e, char *str)
{
	t_moves	*current;

	if (!(current = (t_moves *)malloc(sizeof(t_moves))))
		exit(0);
	if (e->move_end != NULL)
		e->move_end->next = current;
	if (e->move_start == NULL)
		e->move_start = current;
	current->str = str;
	e->move_end = current;
	current->next = NULL;
}
