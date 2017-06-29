/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:15:29 by yli               #+#    #+#             */
/*   Updated: 2017/06/13 21:39:31 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# define LENMOD_H 1
# define LENMOD_HH 2
# define LENMOD_L 3
# define LENMOD_LL 4
# define LENMOD_J 5
# define LENMOD_Z 6

typedef struct	s_flag
{
	int			hash;
	int			minus;
	int			plus;
	int			space;
	int			zero;
}				t_flag;

typedef struct	s_str_fmt
{
	t_flag		flag;
	int			wid;
	int			pre;
	int			length_mod;
	char		conv;
	int			neg_nbr;
	int			cap;
	int			hex;
}				t_str_fmt;

int				ft_parse_fmt(va_list ap, char **format);
int				ft_printf(char *format, ...);

void			parse_format(char **format, t_str_fmt *fmt_struc);
int				parse_width(char **format, t_str_fmt *fmt_struc);
int				parse_precision(char **format, t_str_fmt *fmt_struc);
int				parse_lm(char **format, t_str_fmt *fmt_struc);
int				parse_conv(va_list ap, char **format, t_str_fmt *fmt_struc);

int				parse_dioux(va_list ap, char **fmt, t_str_fmt *fmt_struc);

char			*ft_add_signs(char *str_w_0pad, t_str_fmt *fmt_struc);
char			*ft_add_space(char *str, t_str_fmt *fmt_struc);
char			*ft_mflag(char *str, char *pad, t_str_fmt *fmt_struc);

char			*pre_str_zero(t_str_fmt *fmt_struc);

char			*wid_len_pre(char *str, t_str_fmt *fmt_struc);

char			*ft_set_pad(t_str_fmt *fmt_struc, int len);
char			*ft_add_pad(char *string, t_str_fmt *fmt_struc);

int				ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_ustr(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_ostr(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_xstr(va_list ap, t_str_fmt *fmt_struc);

int				ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_sstr(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_p(va_list ap, t_str_fmt *fmt_struc);
int				ft_conv_pct(t_str_fmt *fmt_struc);

char			*ft_handle_str(char *str, t_str_fmt *fmt_struc);
char			*ft_handle_hex(char *str, t_str_fmt *fmt_struc);

int				parse_other(char **fmt, t_str_fmt *fmt_struc);
char			*ft_handle_oct(char *str, t_str_fmt *fmt_struc);

int				ft_conv_wsstr(va_list ap);
int				ft_conv_wcstr(va_list ap);

uintmax_t		ft_lenmod(va_list ap, t_str_fmt *fmt_struc);
intmax_t		ft_lendmod(va_list ap, t_str_fmt *fmt_struc);

char			*ft_handle_hex(char *str, t_str_fmt *fmt_struc);
char			*ft_add_hash(char *str, t_str_fmt *fmt_struc);
char			*ft_zero_hash(char *str, t_str_fmt *fmt_struc);
char			*x_wid_len_pre(char *str, t_str_fmt *fmt_struc);
char			*x_wid_pre_len(char *str, t_str_fmt *fmt_struc);

char			*str_wid(char *str, t_str_fmt *fmt_struc);
char			*str_len(char *str, t_str_fmt *fmt_struc);

#endif
