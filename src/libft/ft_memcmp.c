/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:06:00 by yli               #+#    #+#             */
/*   Updated: 2016/11/30 11:08:39 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (src1 == NULL && src2 == NULL)
		return (0);
	if (n == 0)
		return (0);
	while (i < n && src1[i] == src2[i])
	{
		i++;
		if (i == (unsigned int)n)
			return (0);
	}
	return (src1[i] - src2[i]);
}
