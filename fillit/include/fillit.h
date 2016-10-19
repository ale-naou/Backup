/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 12:37:35 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/31 17:28:18 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

typedef	struct		s_struct
{
	int				line;
	int				col;
	int				**tab;
	int				tabhash[4];
	int				nbrtetro;
	int				counti;
	int				nbrhash;
	int				i;
	int				x;
	int				y;
	char			*mapmax;
	int				power;
	int				mapopti;
	int				c;
	int				ctetro;
	int				d;

}					t_struct;

void				ft_init(t_struct *global);
int					ft_error(int n);
int					ft_tetrosvalid(char *buf, t_struct *global);
int					ft_linesvalid(char *buf, t_struct *global);
int					ft_resolve(t_struct *global);
int					ft_remove(t_struct *global);
void				ft_reset(t_struct *global);
void				ft_adaptcoordo(t_struct *global);
int					ft_mapopti(t_struct *global);

#endif
