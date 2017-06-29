/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:46:36 by yli               #+#    #+#             */
/*   Updated: 2017/05/23 15:13:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

char		*ft_handle_str(char *str, t_str_fmt *fmt_struc)
{
	char	*pad;
	char	*str_w_spad;
	int		wid;

	wid = fmt_struc->wid;
	if (wid >= fmt_struc->pre && (int)ft_strlen(str) >= fmt_struc->pre
			&& fmt_struc->pre != -1)
		return (str_wid(str, fmt_struc));
	else if (((fmt_struc->pre == -1) && (fmt_struc->wid == 0)) ||
	((fmt_struc->pre == -1) && ((int)ft_strlen(str) >= wid)) ||
	((fmt_struc->pre >= (int)ft_strlen(str)) && ((int)ft_strlen(str) >= wid)))
	{
		if (!(pad = malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		ft_strcpy(pad, str);
		str_w_spad = pad;
		return (str_w_spad);
	}
	else
		return (str_len(str, fmt_struc));
}

char		*str_wid(char *str, t_str_fmt *fmt_struc)
{
	int		wid;
	char	*pad;
	char	*str_w_spad;
	char	*string;

	wid = fmt_struc->wid;
	if (!(pad = malloc(sizeof(char) * (wid - fmt_struc->pre + 1))))
		return (0);
	ft_memset(pad, ' ', (wid - fmt_struc->pre));
	pad[wid - fmt_struc->pre] = '\0';
	if (!(string = malloc(sizeof(char) * fmt_struc->pre)))
		return (0);
	ft_strncpy(string, str, fmt_struc->pre);
	str_w_spad = ft_mflag(string, pad, fmt_struc);
	free(string);
	free(pad);
	return (str_w_spad);
}

char		*str_len(char *str, t_str_fmt *fmt_struc)
{
	int		wid;
	char	*pad;
	char	*final_str;

	wid = fmt_struc->wid;
	if ((int)ft_strlen(str) > fmt_struc->pre && fmt_struc->pre > wid)
	{
		if (!(final_str = malloc(sizeof(char) * (fmt_struc->pre))))
			return (0);
		ft_strncpy(final_str, str, fmt_struc->pre);
	}
	else
	{
		if (!(pad = malloc(sizeof(char) * (wid - ft_strlen(str) + 1))))
			return (0);
		ft_memset(pad, ' ', (wid - ft_strlen(str)));
		pad[(wid - ft_strlen(str))] = '\0';
		final_str = ft_mflag(str, pad, fmt_struc);
		free(pad);
	}
	return (final_str);
}

uintmax_t	ft_lenmod(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;

	i = va_arg(ap, uintmax_t);
	if (fmt_struc->length_mod == LENMOD_H)
		i = (unsigned short)i;
	else if (fmt_struc->length_mod == LENMOD_HH)
		i = (unsigned char)i;
	else if (fmt_struc->length_mod == LENMOD_L)
		i = (unsigned long)i;
	else if (fmt_struc->length_mod == LENMOD_LL)
		i = (unsigned long long)i;
	else if (fmt_struc->length_mod == LENMOD_J)
		i = (uintmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_Z)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	return (i);
}

intmax_t	ft_lendmod(va_list ap, t_str_fmt *fmt_struc)
{
	intmax_t	i;

	i = va_arg(ap, intmax_t);
	if (fmt_struc->length_mod == LENMOD_H)
		i = (short)i;
	else if (fmt_struc->length_mod == LENMOD_HH)
		i = (char)i;
	else if (fmt_struc->length_mod == LENMOD_L)
		i = (long)i;
	else if (fmt_struc->length_mod == LENMOD_LL)
		i = (intmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_J)
		i = (intmax_t)i;
	else if (fmt_struc->length_mod == LENMOD_Z)
		i = (size_t)i;
	else
		i = (int)i;
	return (i);
}
