/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:40:31 by yli               #+#    #+#             */
/*   Updated: 2016/12/04 22:05:14 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (*cs1 != '\0')
	{
		if (*cs2 == '\0' || *cs2 > *cs1 || *cs1 > *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
	}
	return (*cs1 - *cs2);
}
