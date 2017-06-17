/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:13:52 by yli               #+#    #+#             */
/*   Updated: 2016/12/04 22:10:31 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin_count(char const *s)
{
	size_t i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static size_t	ft_end_count(char const *s)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		count++;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	char	*str;
	int		j;

	begin = 0;
	end = 0;
	j = 0;
	if (!s)
		return (NULL);
	begin = ft_begin_count(s);
	end = ft_end_count(s);
	if (ft_strlen(s) - begin <= 0)
		return (ft_strdup(""));
	str = (char *)malloc(ft_strlen(s) -
		(ft_begin_count(s) + ft_end_count(s)) + 1);
	if (!str)
		return (NULL);
	while (s[begin] != '\0' && begin < (ft_strlen(s) - end))
		str[j++] = s[begin++];
	str[j] = '\0';
	return (str);
}
