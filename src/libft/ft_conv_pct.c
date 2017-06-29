/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:05:54 by yli               #+#    #+#             */
/*   Updated: 2017/06/09 11:05:58 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

int	ft_conv_pct(t_str_fmt *fmt_struc)
{
	int		len;
	char	*pad;
	char	*string;
	char	*pct;

	pct = "%";
	len = fmt_struc->wid;
	if (len)
	{
		if (!(pad = malloc(sizeof(char) * len)))
			return (0);
		ft_memset(pad, ' ', len - 1);
		pad[len] = '\0';
		string = ft_mflag(pct, pad, fmt_struc);
		write(1, string, ft_strlen(string));
		free(pad);
		return (len);
	}
	else
	{
		write(1, "%", 1);
		return (1);
	}
}
