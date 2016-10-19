/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:37:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/16 15:28:27 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int c)
{
	if (c == 1)
	{
		ft_putstr("openfd() failed : ");
		ft_putendl("map folder not openable / doesn't exist.");
	}
	if (c == 2)
		ft_putendl("Map invalid : Only handle maps with numbers and spaces.");
	if (c == 3)
		ft_putendl("Map invalid : Lines are not even.");
	if (c == 4)
		ft_putendl("closefd() failed");
	if (c == 5)
		ft_putendl("Alloc failed : axis structure");
	if (c == 6)
		ft_putendl("e->img.adr not created");
	if (c == 7)
		ft_putendl("e->img.img not created");
	exit(0);
}
