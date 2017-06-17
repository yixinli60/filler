/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:22:05 by yli               #+#    #+#             */
/*   Updated: 2017/05/18 15:47:57 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swa(char *a, char *b)
{
	char	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	rev_str(char *str, int len)
{
	int	begin;
	int	end;

	begin = 0;
	end = len - 1;
	while (begin < end)
	{
		ft_swa(str + begin, str + end);
		begin++;
		end--;
	}
}

char	*ft_itoa_base(uintmax_t nbr, char *str, uintmax_t base)
{
	int	i;
	int	rem;

	i = 0;
	rem = 0;
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (nbr != 0)
	{
		rem = nbr % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		nbr = nbr / base;
	}
	str[i] = '\0';
	rev_str(str, i);
	return (str);
}
