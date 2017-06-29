/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:00 by yli               #+#    #+#             */
/*   Updated: 2017/06/09 16:15:02 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

char	*ft_add_hash(char *str, t_str_fmt *fmt_struc)
{
	char	*hash_pad;
	char	*final_str;

	if (fmt_struc->flag.hash)
	{
		hash_pad = ft_strjoin("0x", str);
		final_str = hash_pad;
		return (final_str);
	}
	return (str);
}

char	*ft_zero_hash(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*zero_pad;
	char	*final;

	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - ft_strlen(str) + 1))))
		return (0);
	ft_memset(pad, '0', (fmt_struc->wid - ft_strlen(str)));
	pad[(fmt_struc->wid - ft_strlen(str))] = '\0';
	zero_pad = ft_strjoin(pad, str);
	free(pad);
	if (fmt_struc->flag.hash)
		zero_pad[1] = 'x';
	final = zero_pad;
	free(zero_pad);
	return (final);
}

char	*x_wid_len_pre(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*hash_pad;

	if (fmt_struc->pre == -1 && fmt_struc->flag.zero
			&& !fmt_struc->flag.minus)
		return (ft_zero_hash(str, fmt_struc));
	hash_pad = ft_add_hash(str, fmt_struc);
	if (!(pad = malloc(sizeof(char) *
		(fmt_struc->wid - ft_strlen(hash_pad) + 1))))
		return (0);
	ft_memset(pad, ' ', (fmt_struc->wid - ft_strlen(hash_pad)));
	pad[(fmt_struc->wid - ft_strlen(hash_pad))] = '\0';
	return (ft_mflag(hash_pad, pad, fmt_struc));
}

char	*x_wid_pre_len(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	int		len;
	char	*string;
	char	*fin;

	len = ft_strlen(str);
	if (!(pad = malloc(sizeof(char) * (fmt_struc->pre - len + 1))))
		return (0);
	ft_memset(pad, '0', (fmt_struc->pre - len));
	pad[(fmt_struc->pre - len)] = '\0';
	string = ft_strjoin(pad, str);
	free(pad);
	str = ft_add_hash(string, fmt_struc);
	if (!(pad = malloc(sizeof(char) * (fmt_struc->wid - ft_strlen(str) + 1))))
		return (0);
	ft_memset(pad, ' ', (fmt_struc->wid - ft_strlen(str)));
	pad[(fmt_struc->wid - ft_strlen(str))] = '\0';
	fin = ft_strjoin(pad, str);
	free(pad);
	return (fin);
}

char	*ft_handle_hex(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	int		len;
	char	*final_str;
	char	*final;

	len = ft_strlen(str);
	if ((len >= fmt_struc->pre) && (len >= fmt_struc->wid))
		return (ft_add_hash(str, fmt_struc));
	else if ((fmt_struc->pre > len) && (fmt_struc->pre >= fmt_struc->wid))
	{
		if (!(pad = malloc(sizeof(char) * fmt_struc->pre - len + 1)))
			return (0);
		ft_memset(pad, '0', (fmt_struc->pre - len));
		pad[(fmt_struc->pre - len)] = '\0';
		final = ft_strjoin(pad, str);
		final_str = final;
		free(pad);
		return (ft_add_hash(final_str, fmt_struc));
	}
	else if ((fmt_struc->wid >= len) && (len >= fmt_struc->pre))
		return (x_wid_len_pre(str, fmt_struc));
	else
		return (x_wid_pre_len(str, fmt_struc));
}
