/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:26:01 by yli               #+#    #+#             */
/*   Updated: 2017/05/31 16:32:59 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

int	ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc)
{
	int		i;
	char	str[2];
	char	*string;

	i = va_arg(ap, int);
	if (i == 0)
	{
		if (fmt_struc->wid)
		{
			if (!(string = malloc(sizeof(char) * fmt_struc->wid)))
				return (0);
			ft_memset(string, ' ', fmt_struc->wid - 1);
			string[fmt_struc->wid - 1] = '\0';
			write(1, string, fmt_struc->wid - 1);
			free(string);
			return (fmt_struc->wid);
		}
		write(1, "", 1);
		return (1);
	}
	str[0] = i;
	str[1] = '\0';
	string = ft_handle_str(str, fmt_struc);
	write(1, string, ft_strlen(string));
	return (ft_strlen(string));
}

int	ft_conv_p(va_list ap, t_str_fmt *fmt_struc)
{
	uintmax_t	i;
	char		*str;
	char		*string;
	char		*string_fin;

	string = NULL;
	if (!(str = malloc(sizeof(char) * 20)))
		return (0);
	i = va_arg(ap, uintmax_t);
	if (i == 0)
		str = "0";
	else
		ft_itoa_base(i, str, 16);
	string = ft_strjoin("0x", str);
	string_fin = ft_add_pad(string, fmt_struc);
	write(1, string_fin, ft_strlen(string_fin));
	return (ft_strlen(string_fin));
}

int	ft_conv_sstr(va_list ap, t_str_fmt *fmt_struc)
{
	char	*i;
	char	*final_str;
	int		len;

	i = va_arg(ap, char*);
	if (i == NULL)
		return (write(1, "(null)", 6));
	final_str = ft_handle_str(i, fmt_struc);
	len = ft_strlen(final_str);
	write(1, final_str, len);
	free(final_str);
	return (len);
}

int	ft_conv_wsstr(va_list ap)
{
	wchar_t	*i;
	wchar_t	*n;

	n = NULL;
	i = va_arg(ap, wchar_t*);
	if (i == n)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, i, ft_wstrlen(i) * 4);
	return (0);
}

int	ft_conv_wcstr(va_list ap)
{
	wchar_t	i;
	char	str[4];

	i = va_arg(ap, wchar_t);
	i = (char)i;
	str[0] = i;
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
