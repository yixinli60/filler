/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:52:05 by yli               #+#    #+#             */
/*   Updated: 2016/12/06 14:53:06 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(uintmax_t *a, uintmax_t *b)
{
	uintmax_t t;

	t = *a;
	*a = *b;
	*b = t;
}
