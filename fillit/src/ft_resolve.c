/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/30 17:03:10 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place(t_struct *global)
{
	int tmp;

	global->x = 0;
	tmp = global->tab[global->y][0];
	while (global->x <= 3)
	{
		global->mapmax[tmp] = global->c;
		global->x++;
		tmp = tmp + global->tab[global->y][global->x];
	}
	global->c++;
	global->i = 0;
	return (0);
}

int		ft_isplacable(t_struct *global)
{
	int		tmp;

	while (global->mapmax[global->i] != '\0')
	{
		if (global->mapmax[global->i] == '.')
		{
			global->x = 1;
			tmp = global->i;
			global->tab[global->y][0] = global->i;
			while (global->mapmax[tmp +
					global->tab[global->y][global->x]] == '.' && global->x <= 3)
			{
				if (global->x == 3)
				{
					ft_place(global);
					global->y++;
					return (0);
				}
				tmp = tmp + global->tab[global->y][global->x];
				global->x++;
			}
		}
		global->i++;
	}
	return (1);
}

int		ft_remove(t_struct *global)
{
	int tmp;

	global->y--;
	if (global->y == -1)
		return (global->y);
	global->x = 1;
	global->i = global->tab[global->y][0];
	tmp = global->i;
	while (global->x <= 4)
	{
		global->mapmax[tmp] = '.';
		tmp = tmp + global->tab[global->y][global->x];
		global->x++;
	}
	global->i++;
	global->c--;
	return (0);
}

void	ft_reset(t_struct *global)
{
	global->i = 0;
	global->y = 0;
	global->x = 0;
	global->power++;
	ft_mapopti(global);
	ft_adaptcoordo(global);
	global->i = 0;
	global->y = 0;
	global->x = 0;
}

int		ft_resolve(t_struct *global)
{
	global->mapmax = ft_strnew(16 * 17);
	global->col = 4;
	ft_mapopti(global);
	ft_adaptcoordo(global);
	global->i = 0;
	global->y = 0;
	while (1)
	{
		if ((ft_isplacable(global)) == 1)
		{
			if (ft_remove(global) == -1)
			{
				ft_reset(global);
			}
		}
		if (global->y == global->nbrtetro)
		{
			ft_putstr(global->mapmax);
			return (0);
		}
	}
	return (0);
}
