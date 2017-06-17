/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:51:29 by yli               #+#    #+#             */
/*   Updated: 2016/11/28 19:53:47 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	i = 0;
	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if ((cs1[i] == '\0' || cs2[i] == '\0') && n == 0)
		return (0);
	while (cs1[i] != '\0' && cs2[i] != '\0' && cs1[i] == cs2[i] && i < n)
		i++;
	if (i == n)
		return (cs1[i - 1] - cs2[i - 1]);
	return (cs1[i] - cs2[i]);
}
