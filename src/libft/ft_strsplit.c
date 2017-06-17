/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:50:28 by yli               #+#    #+#             */
/*   Updated: 2016/12/05 17:19:57 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_nbrwords(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		wd_nbr;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	wd_nbr = ft_nbrwords(s, c);
	t = (char **)malloc(sizeof(*t) * (wd_nbr + 1));
	if (t == NULL)
		return (NULL);
	while (wd_nbr--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub(s, 0, ft_wdlen(s, c));
		if (t[index] == NULL)
			return (NULL);
		s = s + ft_wdlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
