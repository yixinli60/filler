/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:27:08 by yli               #+#    #+#             */
/*   Updated: 2017/05/04 13:55:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

int			ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc)
{
	intmax_t	i;
	intmax_t	nbr;
	char		*string;
	char		*str;
	int			len;

	i = ft_lendmod(ap, fmt_struc);
	if (i < 0)
		fmt_struc->neg_nbr = 1;
	nbr = ft_absval(i);
	str = ft_itoa(nbr);
	string = ft_add_pad(str, fmt_struc);
	len = ft_strlen(string);
	write(1, string, len);
	free(str);
	return (len);
}

int			ft_conv_ostr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		str[100];
	char		*string_0;

	i = ft_lenmod(ap, fmt_struc);
	ft_itoa_base(i, str, 8);
	if (fmt_struc->flag.hash && (str[0] != '0'))
		string_0 = ft_strjoin("0", str);
	else
		string_0 = str;
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_0);
	string_fin = ft_add_pad(string_0, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int			ft_conv_ustr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string;

	i = ft_lenmod(ap, fmt_struc);
	string = ft_add_pad(ft_itoa(i), fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}

int			ft_conv_xstr(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*string_fin;
	char		str[100];

	string_fin = NULL;
	i = ft_lenmod(ap, fmt_struc);
	ft_itoa_base(i, str, 16);
	if (*str == '0')
	{
		if (fmt_struc->pre == -1 && fmt_struc->wid == 0)
		{
			write(1, "0", 1);
			return (1);
		}
		else
			string_fin = ft_handle_str(str, fmt_struc);
	}
	else
		string_fin = ft_handle_hex(str, fmt_struc);
	if (fmt_struc->cap == 1)
		ft_strtoupper(string_fin);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}
