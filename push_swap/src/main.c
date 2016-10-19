/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:27:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/07 13:43:53 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_env *e)
{
	e->a_start = NULL;
	e->b_start = NULL;
	e->a_end = NULL;
	e->b_end = NULL;
	e->move_start = NULL;
	e->move_end = NULL;
	e->i = 0;
	e->j = 0;
	e->k = 0;
	e->color = 0;
	e->stack_display = 0;
}

static void	aff_help(void)
{
	ft_putchar('	');
	ft_putendl("Usage	: ./push_swap [-c] [-s] Arguments list.");
	ft_putchar('	');
	ft_putendl("[-c]	: Add color on moves.");
	ft_putchar('	');
	ft_putendl("[-s]	: Display stacks state after every move.");
	exit(0);
}

static int	create_list(t_env *e, int ac, char **av)
{
	t_struct	*tmp;

	tmp = NULL;
	e->i = e->color + e->stack_display;
	if (av[e->i + 1] != NULL)
		if (!(tmp = (t_struct *)malloc(sizeof(t_struct))))
			error(e, 1);
	e->a_start = tmp;
	while (++e->i < ac)
	{
		tmp->n = ft_atoi(av[e->i]);
		tmp->next = NULL;
		if (e->i + 1 < ac)
		{
			if (!(tmp->next = (t_struct *)malloc(sizeof(t_struct))))
				error(e, 1);
			tmp = tmp->next;
		}
	}
	e->a_end = tmp;
	return (0);
}

int			main(int ac, char **av)
{
	t_env		e;

	if (ac >= 2)
	{
		if (ft_strcmp(av[1], "-help") == 0)
			aff_help();
		init(&e);
		read_args(&e, ac, av);
		create_list(&e, ac, av);
		e.stack_display == 1 ? print_stack(&e) : 0;
		sort_last(&e);
		algo(&e);
		print_moves(&e);
	}
	return (0);
}
