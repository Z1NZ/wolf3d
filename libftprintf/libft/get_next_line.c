/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 02:25:32 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:09:27 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	create_and_cut_da_line(char **str, char *slash, char **line, char *buf)
{
	char *next_lign;

	ft_strdel(&buf);
	next_lign = NULL;
	if (ft_strequ(*str, "\n"))
		*line = ft_strdup("");
	else if (!slash)
		*line = ft_strdup(*str);
	else if (slash)
	{
		slash[0] = '\0';
		*line = ft_strdup(*str);
		if (slash[1])
			next_lign = ft_strdup(&slash[1]);
	}
	ft_strdel(str);
	if (next_lign)
		*str = next_lign;
	return (1);
}

int	end_del(char *buf)
{
	ft_strdel(&buf);
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	char		*buf;
	char		*slash;
	char		*next_lign;
	static char	*str;
	int			ret;

	ret = 1;
	if ((buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((slash = ft_strchr(str, '\n')) == NULL
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		next_lign = ft_strjoin(str, buf);
		if (str != NULL)
			ft_strdel(&str);
		str = next_lign;
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && !str)
		return (end_del(buf));
	return (create_and_cut_da_line(&str, slash, line, buf));
}
