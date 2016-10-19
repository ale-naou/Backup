/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:25:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 19:30:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			color_moves(char *move)
{
	ft_strcmp(move, "sa") == 0 ? ft_putstr(C_MAG) : 0;
	ft_strcmp(move, "sb") == 0 ? ft_putstr(C_MAG) : 0;
	ft_strcmp(move, "ss") == 0 ? ft_putstr(C_MAG) : 0;
	ft_strcmp(move, "pa") == 0 ? ft_putstr(C_RED) : 0;
	ft_strcmp(move, "pb") == 0 ? ft_putstr(C_RED) : 0;
	ft_strcmp(move, "ra") == 0 ? ft_putstr(C_LBLUE) : 0;
	ft_strcmp(move, "rb") == 0 ? ft_putstr(C_LBLUE) : 0;
	ft_strcmp(move, "rr") == 0 ? ft_putstr(C_LBLUE) : 0;
	ft_strcmp(move, "rra") == 0 ? ft_putstr(C_YELLOW) : 0;
	ft_strcmp(move, "rrb") == 0 ? ft_putstr(C_YELLOW) : 0;
	ft_strcmp(move, "rrr") == 0 ? ft_putstr(C_YELLOW) : 0;
}

void			print_moves(t_env *e)
{
	t_moves		*tmp;

	tmp = e->move_start;
	while (tmp != NULL)
	{
		e->color == 1 ? color_moves(tmp->str) : 0;
		ft_putstr(tmp->str);
		if (tmp->next == NULL)
		{
			ft_putchar('\n');
			break ;
		}
		ft_putchar(' ');
		tmp = tmp->next;
		e->color == 1 ? ft_putstr(C_END) : 0;
	}
}

static void		print_stack_b(t_env *e)
{
	t_struct	*tmp;

	tmp = e->b_start;
	e->color == 1 ? ft_putstr(C_GREY) : 0;
	ft_putstr("B : ");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->n);
		if (tmp->next == NULL)
		{
			ft_putchar('\0');
			break ;
		}
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
	e->color == 1 ? ft_putstr(C_END) : 0;
}

static void		print_stack_a(t_env *e)
{
	t_struct	*tmp;

	tmp = e->a_start;
	e->color == 1 ? ft_putstr(C_CYAN) : 0;
	ft_putstr("A : ");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->n);
		if (tmp->next == NULL)
		{
			ft_putchar('\n');
			break ;
		}
		ft_putchar(' ');
		tmp = tmp->next;
	}
	e->color == 1 ? ft_putstr(C_END) : 0;
}

void			print_stack(t_env *e)
{
	if (e->a_start != NULL || e->b_start != NULL)
	{
		print_stack_a(e);
		print_stack_b(e);
	}
}
