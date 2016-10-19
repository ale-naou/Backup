/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:19:07 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/30 18:08:21 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_size(int n)
{
	int	size;

	if (n < 0 && -n < 0)
		return (11);
	size = n < 0 ? 1 : 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*end;
	int		size;
	int		n_xtrm;

	size = get_nb_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	end = str + size - 1;
	*(str + size) = '\0';
	n_xtrm = (n < 0 && -n < 0) ? 1 : 0;
	if (n < 0)
	{
		*str = '-';
		n = n_xtrm ? -(n + 1) : -n;
	}
	while (n >= 10 && end >= str)
	{
		*end = (char)(n % 10) + '0' + (n_xtrm && end == str + size - 1 ? 1 : 0);
		n /= 10;
		end--;
	}
	if (end >= str)
		*end = (char)(n) + '0';
	return (str);
}
