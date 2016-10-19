/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:56:16 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:14:18 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_len_unsigned(unsigned long long int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (1);
	while ((n /= 10) > 0)
		len++;
	return (len);
}
