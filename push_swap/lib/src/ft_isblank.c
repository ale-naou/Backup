/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:17:11 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/07 16:17:12 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' ||
			c == '\t' || c == '\r' || c == '\f'));
}