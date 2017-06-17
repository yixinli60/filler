/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:11:14 by yli               #+#    #+#             */
/*   Updated: 2016/11/28 16:13:25 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*cdst;
	const char	*csrc;
	size_t		n;
	size_t		dlen;

	cdst = dst;
	csrc = src;
	n = size;
	while (n-- != 0 && *cdst != '\0')
		cdst++;
	dlen = cdst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(csrc));
	while (*csrc != '\0')
	{
		if (n != 1)
		{
			*cdst++ = *csrc;
			n--;
		}
		csrc++;
	}
	*cdst = '\0';
	return (dlen + (csrc - src));
}
