/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:02:26 by yli               #+#    #+#             */
/*   Updated: 2017/05/17 12:02:30 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

char		*pre_str_zero(t_str_fmt *fmt_struc)
{
	char	*pad_w_spad;
	char	*final_str;

	if (fmt_struc->flag.plus && (fmt_struc->wid == 0))
	{
		if (!(pad_w_spad = malloc(sizeof(char) * 2)))
			return (0);
		ft_memset(pad_w_spad, '+', 1);
	}
	else
	{
		if (!(pad_w_spad = malloc(sizeof(char) * (fmt_struc->wid) + 1)))
			return (0);
		ft_memset(pad_w_spad, ' ', (fmt_struc->wid));
		pad_w_spad[fmt_struc->wid] = '\0';
		if (fmt_struc->flag.plus)
			pad_w_spad[fmt_struc->wid - 1] = '+';
	}
	final_str = pad_w_spad;
	free(pad_w_spad);
	return (final_str);
}

char		*wid_len_pre(char *str, t_str_fmt *fmt_struc)
{
	int		len;
	char	*pad;
	char	*n_str;
	char	*str_w_0pad;

	n_str = ft_add_signs(str, fmt_struc);
	len = ft_strlen(n_str);
	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - len + 1))))
		return (0);
	pad[(fmt_struc->wid - len)] = '\0';
	if (fmt_struc->pre == -1 && fmt_struc->flag.zero && !fmt_struc->flag.minus)
	{
		ft_memset(pad, '0', (fmt_struc->wid - len));
		n_str = ft_strjoin(pad, str);
		free(pad);
		return (ft_add_signs(n_str, fmt_struc));
	}
	ft_memset(pad, ' ', (fmt_struc->wid - len));
	str_w_0pad = ft_mflag(n_str, pad, fmt_struc);
	free(pad);
	return (str_w_0pad);
}

char		*ft_set_pad(t_str_fmt *fmt_struc, int len)
{
	char	*pad;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->pre - len + 1))))
		return (0);
	ft_memset(pad, '0', (fmt_struc->pre - len));
	pad[(fmt_struc->pre - len)] = '\0';
	return (pad);
}

char		*ft_add_pad(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_0pad;
	int		len;

	len = ft_strlen(str);
	if (fmt_struc->pre == 0 && *str == '0' && !fmt_struc->flag.hash)
		return (pre_str_zero(fmt_struc));
	else if (fmt_struc->wid >= len && len >= fmt_struc->pre)
		return (wid_len_pre(str, fmt_struc));
	else if (fmt_struc->pre >= len && fmt_struc->pre >= fmt_struc->wid)
	{
		pad = ft_set_pad(fmt_struc, len);
		str_w_0pad = ft_add_signs(ft_strjoin(pad, str), fmt_struc);
		return (str_w_0pad);
	}
	else if (fmt_struc->wid >= fmt_struc->pre && fmt_struc->pre >= len)
	{
		pad = ft_set_pad(fmt_struc, len);
		str_w_0pad = ft_add_signs(ft_strjoin(pad, str), fmt_struc);
		free(pad);
		return (ft_add_space(str_w_0pad, fmt_struc));
	}
	return (ft_add_signs(str, fmt_struc));
}
