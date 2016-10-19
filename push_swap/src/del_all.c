/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:42:11 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 17:17:45 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_all(t_env *e)
{
	t_struct	*tmp;
	t_moves		*tmp2;

	while (e->a_start != NULL)
	{
		tmp = e->a_start->next;
		free(e->a_start);
		e->a_start = NULL;
		e->a_start = tmp;
	}
	while (e->move_start->str != NULL)
	{
		tmp2 = e->move_start->next;
		if (e->move_start->str != NULL)
		{
			free(e->move_start->str);
			e->move_start->str = NULL;
		}
		free(e->move_start);
		e->move_start = NULL;
		e->move_start = tmp2;
	}
}
