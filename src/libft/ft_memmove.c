/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:55:10 by yli               #+#    #+#             */
/*   Updated: 2016/11/30 19:03:03 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (csrc < cdst)
	{
		cdst += len - 1;
		csrc += len - 1;
		while (len > 0)
		{
			*cdst-- = *csrc--;
			len--;
		}
	}
	else
		while (len)
		{
			*cdst++ = *csrc++;
			len--;
		}
	return (dst);
}
