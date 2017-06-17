/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:17:19 by yli               #+#    #+#             */
/*   Updated: 2017/03/15 18:44:54 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_line(char **sb, char **line)
{
	char	*leftover;
	char	*ptr_to_nl;

	ptr_to_nl = ft_strchr(*sb, '\n');
	if (ptr_to_nl)
	{
		*line = ft_strndup(*sb, ptr_to_nl - *sb);
		leftover = ft_strdup(ptr_to_nl + 1);
		free(*sb);
		if (!leftover || !*line)
		{
			ft_strdel(&leftover);
			ft_strdel(line);
			*sb = NULL;
			return (1);
		}
		*sb = leftover;
	}
	else
	{
		*line = *sb;
		*sb = NULL;
	}
	return (0);
}

static int	read_to_static_buf(int fd, char **sb)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;
	_Bool	read_something;

	read_something = false;
	if (*sb == NULL)
		*sb = ft_strdup("");
	if (*sb == NULL)
		return (-1);
	while (ft_strchr(*sb, '\n') == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (-1);
		read_something = true;
		buf[ret] = '\0';
		tmp = ft_strjoin(*sb, buf);
		free(*sb);
		if ((*sb = tmp) == NULL)
			return (-1);
	}
	return (read_something || **sb);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*static_buf;

	ret = 0;
	if (fd < 0 || !line || ((ret = read_to_static_buf(fd, &static_buf)) < 0)
		|| set_line(&static_buf, line))
		return (-1);
	return (ret);
}
