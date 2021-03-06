/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:47:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 22:55:44 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*del;
	char		buf[BUFF_SIZE + 1];
	static char	*s[255];

	if (!line || fd < 0 || !(s[fd] = (s[fd] == NULL ? ft_strnew(1) : s[fd])))
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		del = s[fd];
		buf[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buf);
		free(del);
	}
	if (ret == -1)
		return (-1);
	*line = (ft_strchr(s[fd], '\n') ? ft_strsub(s[fd], 0,
				ft_strchr(s[fd], '\n') - s[fd]) : ft_strdup(s[fd]));
	if (ft_strchr((del = s[fd]), '\n'))
		s[fd] = ft_strsub(s[fd], ft_strchr(s[fd], '\n') - s[fd] + 1,
				ft_strlen(s[fd]));
	else
		s[fd] = ft_strsub(s[fd], ft_strlen(*line), ft_strlen(s[fd]));
	free(del);
	return (!ret && !ft_strlen(*line) && !ft_strlen(s[fd]) ? 0 : 1);
}
