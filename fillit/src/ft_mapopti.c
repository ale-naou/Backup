/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapopti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 23:40:34 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/30 17:03:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_adaptcoordo(t_struct *global)
{
	global->y = 0;
	while (global->y < global->nbrtetro)
	{
		global->x = 1;
		while (global->x <= 3)
		{
			if (global->tab[global->y][global->x] == 1)
				global->x++;
			else
			{
				global->tab[global->y][global->x] =
					global->tab[global->y][global->x] -
					(global->col - global->power);
				global->x++;
			}
		}
		global->y++;
	}
	global->col = global->power;
}

int		ft_mapopti(t_struct *global)
{
	int	i;

	i = 0;
	global->x = 0;
	while (global->power * global->power < global->nbrtetro * 4)
		global->power++;
	global->mapopti = global->power * global->power + global->power;
	while (i < global->mapopti)
	{
		if (global->x == global->power)
		{
			global->mapmax[i] = '\n';
			i++;
			global->x = 0;
		}
		else
		{
			global->mapmax[i] = '.';
			i++;
			global->x++;
		}
	}
	global->mapmax[i] = '\0';
	return (global->mapopti);
}
