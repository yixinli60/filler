#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:07:35 by yli               #+#    #+#              #
#    Updated: 2017/06/02 15:51:43 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
CFLAGS =  -Wall -Wextra -Werror -c -I

OBJECTS = ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memccpy.o \
	ft_memmove.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strlen.o \
	ft_strdup.o \
	ft_strndup.o \
	ft_strcpy.o \
	ft_strncpy.o \
	ft_strcat.o \
	ft_strncat.o \
	ft_strlcat.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strstr.o \
	ft_strnstr.o \
	ft_strcmp.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_memalloc.o \
	ft_memdel.o \
	ft_strnew.o \
	ft_strdel.o \
	ft_strclr.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strequ.o \
	ft_strnequ.o \
	ft_strsub.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_strsplit.o \
	ft_itoa.o \
	ft_putchar.o \
	ft_putstr.o \
	ft_putendl.o \
	ft_putnbr.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_lstnew.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_isspace.o \
	ft_max.o \
	ft_swap.o \
	ft_strtolower.o \
	ft_strtoupper.o \
	ft_pwr.o \
	ft_strtolower.o \
	ft_strtoupper.o \
	ft_get_int_len.o \
	ft_absval.o \
	ft_itoa_base.o \
	ft_str_toupper.o \
	ft_wstrlen.o \
	get_next_line.o \
	parsing.o \
	printing.o \
	parse_dioux.o \
	ft_printf.o \
	ft_pad_str.o \
	ft_handle_str.o \
	ft_handle_hex.o \
	ft_conv_pct.o \
	ft_conv_cps.o \
	ft_conv_dioux.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -rf $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
