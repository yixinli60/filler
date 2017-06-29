/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:39:23 by yli               #+#    #+#             */
/*   Updated: 2017/05/31 15:39:52 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "include/ft_printf.h"

int	parse_dioux(va_list ap, char **fmt, t_str_fmt *fmt_struc)
{
	int	len;

	len = 0;
	if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
	{
		fmt_struc->length_mod = LENMOD_L;
		fmt_struc->cap = 1;
	}
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
		return (len = ft_conv_dstr(ap, fmt_struc));
	else if (**fmt == 'o' || **fmt == 'O')
		return (len = ft_conv_ostr(ap, fmt_struc));
	else if (**fmt == 'u' || **fmt == 'U')
		return (len = ft_conv_ustr(ap, fmt_struc));
	else if (**fmt == 'x' || **fmt == 'X')
	{
		fmt_struc->hex = 1;
		if (**fmt == 'X')
			fmt_struc->cap = 1;
		return (len = ft_conv_xstr(ap, fmt_struc));
	}
	return (0);
}

int	parse_other(char **fmt, t_str_fmt *fmt_struc)
{
	int		width;

	width = fmt_struc->wid;
	if (**fmt == '\0')
		return (0);
	while (**fmt != '\0')
	{
		write(1, *fmt, 1);
		(*fmt)++;
	}
	return (1);
}
