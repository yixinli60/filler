/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:04:46 by yli               #+#    #+#             */
/*   Updated: 2016/12/04 16:05:43 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *strjoin;
	char *new_str;

	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc(sizeof(*strjoin) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (NULL);
	new_str = ft_strcpy(strjoin, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}
