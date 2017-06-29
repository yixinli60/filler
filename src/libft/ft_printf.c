/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:01:01 by yli               #+#    #+#             */
/*   Updated: 2017/04/25 15:17:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

int	ft_parse_fmt(va_list ap, char **format)
{
	int			len;
	t_str_fmt	fmt_struc;

	len = 0;
	ft_memset(&fmt_struc, 0, sizeof(fmt_struc));
	parse_format(format, &fmt_struc);
	parse_width(format, &fmt_struc);
	parse_precision(format, &fmt_struc);
	parse_lm(format, &fmt_struc);
	len = parse_conv(ap, format, &fmt_struc);
	(*format)++;
	return (len);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len = len + ft_parse_fmt(ap, &format);
		}
		else
		{
			write(1, format, 1);
			(format)++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
