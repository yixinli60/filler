/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:19:51 by yli               #+#    #+#             */
/*   Updated: 2017/04/25 14:41:37 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

void	parse_format(char **fmt, t_str_fmt *fmt_struc)
{
	while (ft_strchr("#-+ 0", **fmt))
	{
		if (**fmt == '#')
			fmt_struc->flag.hash = 1;
		else if (**fmt == '-')
			fmt_struc->flag.minus = 1;
		else if (**fmt == '+')
			fmt_struc->flag.plus = 1;
		else if (**fmt == ' ')
			fmt_struc->flag.space = 1;
		else if (**fmt == '0')
			fmt_struc->flag.zero = 1;
		(*fmt)++;
	}
}

int		parse_width(char **format, t_str_fmt *fmt_struc)
{
	int	width;

	width = 0;
	while ((**format >= '0' && **format <= '9'))
	{
		width *= 10;
		width += **format - '0';
		(*format)++;
	}
	return (fmt_struc->wid = width);
}

int		parse_precision(char **format, t_str_fmt *fmt_struc)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		precision = 0;
		(*format)++;
		while ((**format >= '0' && **format <= '9'))
		{
			precision *= 10;
			precision += **format - '0';
			(*format)++;
		}
	}
	return (fmt_struc->pre = precision);
}

int		parse_lm(char **format, t_str_fmt *fmt_struc)
{
	if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h')
			fmt_struc->length_mod = LENMOD_HH;
		else
			return (fmt_struc->length_mod = LENMOD_H);
	}
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
			fmt_struc->length_mod = LENMOD_LL;
		else
			return (fmt_struc->length_mod = LENMOD_L);
	}
	else if (**format == 'j')
		fmt_struc->length_mod = LENMOD_J;
	else if (**format == 'z')
		fmt_struc->length_mod = LENMOD_Z;
	else
		return (0);
	(*format)++;
	return (0);
}

int		parse_conv(va_list ap, char **fmt, t_str_fmt *fmt_struc)
{
	static int len;

	len = 0;
	fmt_struc->conv = **fmt;
	if (ft_strchr("dDioOuUxX", **fmt))
		return (parse_dioux(ap, fmt, fmt_struc));
	else if (**fmt == 'c' || **fmt == 'C')
	{
		if (**fmt == 'C' || fmt_struc->length_mod == 'l')
			return (len = ft_conv_wcstr(ap));
		return (len = ft_conv_cstr(ap, fmt_struc));
	}
	else if (**fmt == 's' || **fmt == 'S')
	{
		if (**fmt == 'S' || fmt_struc->length_mod == 'l')
			return (len = ft_conv_wsstr(ap));
		return (len = ft_conv_sstr(ap, fmt_struc));
	}
	else if (**fmt == 'p')
		return (len = ft_conv_p(ap, fmt_struc));
	else if (**fmt == '%')
		return (len = ft_conv_pct(fmt_struc));
	else
		return (len = parse_other(fmt, fmt_struc));
}
